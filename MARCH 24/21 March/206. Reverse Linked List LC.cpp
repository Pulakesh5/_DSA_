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
    ListNode* reverseHead;
    ListNode* reverse(ListNode* head)
    {
        if(head==nullptr)
            return nullptr;
        if(head->next == nullptr)
            reverseHead = head;
        ListNode* revList = reverse(head->next);
        if(revList)
        {
            revList->next = head;
            head->next = nullptr;
        }
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        reverse(head);
        return reverseHead;
    }
};
