/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *mergedList = new ListNode(-1);
        ListNode *prev = mergedList, *ptr = head->next;
        int sum = 0;
        while(ptr != nullptr)
        {
            if(ptr->val==0)
            {
                prev->next = new ListNode(sum);
                prev = prev->next;
                sum = 0;
            }
            else
            {
                sum+=ptr->val;
            }
            ptr = ptr->next;
        }
        return mergedList->next;
    }
};
