class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node *ptr1 = head1, *ptr2 = head2, *merged, *ans;
        if(ptr1->data <= ptr2->data)
        {
            ans = ptr1;
            merged = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ans = ptr2;
            merged = ptr2;
            ptr2 = ptr2->next;
        }
        while(ptr1!=nullptr && ptr2!=nullptr)
        {
            if(ptr1->data <= ptr2->data)
            {
                merged->next = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                merged->next = ptr2;
                ptr2 = ptr2->next;
            }
            merged = merged->next;
        }
        while(ptr1!=nullptr)
        {
            merged->next = ptr1;
            ptr1 = ptr1->next;
            merged = merged->next;
        }
        while(ptr2!=nullptr)
        {
            merged->next = ptr2;
            ptr2 = ptr2->next;
            merged = merged->next;
        }
        return ans;
    }
};
