class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        if(!head)
            return head;

        Node* temp=head;
        while(temp!=NULL) // original-cloned-original-cloned...
        {
            Node* newnode=new Node(temp->data);
            newnode->next=temp->next;
            temp->next=newnode;
            
            temp=temp->next->next;
        }
        
        temp=head;
        
        while(temp!=NULL)
        {
            Node* copy=temp->next;
            if(temp->random!=NULL)
            {
              copy->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        temp=head;
        Node* dummy=new Node(-1);
        Node* curr=dummy;
        while(temp!=NULL)
        {
            curr->next=temp->next;
            temp->next=temp->next->next;
            curr=curr->next;
            temp=temp->next;
        }
        return dummy->next;
    }
};
