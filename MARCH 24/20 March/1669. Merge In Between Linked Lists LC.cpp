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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int pos = 0;
        ListNode *prev, *curr = list1;
        while(pos<a)
        {
            prev = curr;
            curr = curr->next;
            pos++;
        }
        // cout<<prev->val<<" "<<curr->val<<endl;
        prev->next = list2;
        while(pos<=b)
        {
            prev = curr;
            curr = curr->next;
            pos++;
        }
        // cout<<prev->val<<" "<<curr->val<<endl;
        prev = curr;
        curr = list2;
        while(curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = prev;
        return list1;
    }
};
