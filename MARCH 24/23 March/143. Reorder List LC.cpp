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
    void reorderList(ListNode* head) {
        ListNode* reorderedList = new ListNode(-1);
        ListNode* answer = reorderedList;

        stack<ListNode*> stk;
        ListNode* root = head;
        int len = 0;
        while(root)
        {
            stk.push(root);
            root = root->next;
            len++;
        }
        ListNode* pptr = head;
        for(int t=0; t<(len/2); t++)
        {
            ListNode* lastNode = stk.top();
            stk.pop();
            lastNode->next = pptr->next;
            pptr->next = lastNode;
            pptr = lastNode->next;
        }
        pptr->next = nullptr;
        // return answer;
    }
};
