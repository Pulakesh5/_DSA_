/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head, *slow=head;

        while(fast && fast->next && slow)
        {
            fast=fast->next->next;
            slow=slow->next;

            if(slow==fast)
            {
                break;
            }
        }

        if(!fast || !(fast->next) || !slow)
            return NULL;
        fast=head;

        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }

        return fast;

    }
};
