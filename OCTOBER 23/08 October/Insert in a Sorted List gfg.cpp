class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node* start = head;
        Node* newNode = new Node(data);
        Node* nxt;
        bool flag = false;
        if(data < start->data)
        {
            newNode->next = start;
            return newNode;
        }
        while(start->next && !flag)
        {
            if(data >= start->data && data < start->next->data)
            {
                nxt = start->next;
                start->next = newNode;
                newNode->next = nxt;
                flag = true;
            }
            else
                start = start->next;
        }
        if(start->next == NULL)
        {
            start->next = newNode;
        }
        return head;
    }
};
