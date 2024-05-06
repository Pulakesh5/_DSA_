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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* auxHead = head;
        while(auxHead!=nullptr)
        {
            stk.push(auxHead);
            auxHead = auxHead->next;
        }
        ListNode *newHead = stk.top(), *tmpHead;
        stk.pop();
        int maxToRight = newHead->val;
        while(!stk.empty())
        {
            if(stk.top()->val>=maxToRight)
            {
                tmpHead = stk.top();
                tmpHead->next = newHead;
                maxToRight = max(maxToRight,tmpHead->val);
                newHead = tmpHead;
            }
            stk.pop();
        }
        return newHead;
    }
    
};
