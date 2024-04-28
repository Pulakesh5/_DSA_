Node* deleteMid(Node* head)
    {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        Node* temp = head;
        unordered_map<int, Node*> mp;
        int n = 0;
        while(temp != NULL){
            n++;
            mp[n] = temp;
            temp = temp->next;
        }
        n = n/2;
        mp[n]->next = mp[n+2]; 
        return head;
    }
