class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        while(slow && fast)
        {
            if(fast->next == NULL || fast->next->next==NULL)
                return false;
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
    }
};
