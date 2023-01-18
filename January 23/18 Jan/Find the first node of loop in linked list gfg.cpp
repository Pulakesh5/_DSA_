    int findFirstNode(Node* head)
    {
        // your code here
        Node *fast=head, *slow=head;
        
        while(fast && fast->next)
        {
            //cout<<slow->data<<" "<<fast->data<<endl;
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                break;
        }
        if(slow!=fast) return -1;
        //cout<<slow->data<<endl;
        slow=head;
        
        while(slow!=fast)
        {
            //cout<<slow->data<<" "<<fast->data<<endl;
            slow=slow->next;
            fast=fast->next;
        }
        return fast->data;
        
    }
