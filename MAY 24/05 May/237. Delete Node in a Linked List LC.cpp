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
    void deleteNode(ListNode* node) {
        ListNode *prev, *curr=node;
        while(curr->next)
        {
            prev = curr;
            curr->val = curr->next->val;
            curr = curr->next;
        }
        prev->next = nullptr;
    }
};
