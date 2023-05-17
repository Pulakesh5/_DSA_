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
    int pairSum(ListNode* head) {
        long long twinSum=0;
        ListNode* rev = head;
        rec(head, rev, twinSum);
        return twinSum;
    }
    void rec(ListNode* &head, ListNode* rev, long long &twinSum)
    {
        if(!rev)
            return;
        rec(head, rev->next, twinSum);
        twinSum = max(twinSum, 0ll+rev->val+head->val);
        head = head->next;
    }
};
