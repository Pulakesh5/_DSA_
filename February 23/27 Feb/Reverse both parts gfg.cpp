Node* help(Node*& t1, Node*& t2)
    {
        Node* prev = NULL;
        Node* curr = t1;
        Node* curr_next;
        while(curr != t2)
        {
            curr_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_next;
        }
        curr->next = prev;
        return curr;
    }
    Node *reverse(Node *head, int k)
    {
        Node* t1 = head;
        Node* t2 = head;
        k--;
        while(k--)
        {
            t2 = t2->next;
        }
        Node* t11 = t2->next;
        Node* k1 = help(t1, t2);
        t1 = t11;
        t2 = t1;
        while(t2->next != NULL)
        {
            t2 = t2->next;
        }
        Node* k2 = help(t1, t2);
        head->next = k2;
        return k1;
    }
