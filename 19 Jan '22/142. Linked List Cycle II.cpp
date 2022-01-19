/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    Read Floyd's Algorithm
    
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head, *slow=head;
        bool cycle=false;
        while(fast && slow && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cycle=true;
                break;
            }
        }
        if(!cycle) return NULL;
        fast= head;
        while(fast!=slow){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
