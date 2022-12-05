class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast=head, *slow=head;
        while(fast && slow)
        {
            if(!(fast->next)) return slow;
            if((fast->next) && !(fast->next->next)) return slow->next;
            slow=slow->next;
            fast=fast->next->next;
        }
        return NULL;
    }
};
