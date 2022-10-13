class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *prev=node,*curr=node->next;
        
        while(curr->next)
        {
            swap(prev->val,curr->val);
            prev=prev->next;
            curr=curr->next;
        }
        swap(prev->val,curr->val);
        delete(curr);
        prev->next=NULL;
        
    }
};
