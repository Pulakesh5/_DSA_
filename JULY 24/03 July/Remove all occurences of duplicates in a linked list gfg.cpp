
class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        if(head==nullptr || head->next==nullptr)
            return head;
        
        Node* dummy = new Node(-1);
        dummy->next = head;
        Node *prev = dummy, *ptr = head;
        
        int data;
        bool duplicate = false;
        while(ptr != nullptr)
        {
            duplicate = false;
            data = ptr->data;
            while(ptr->next!=nullptr && (ptr->next->data==data))
            {
                duplicate = true;
                ptr = ptr->next;
            }
            
            if(duplicate)
                prev->next = ptr->next;
            else

                prev = prev->next;
            }
            
            ptr = ptr->next;
        }
        return dummy->next;
    }
};
