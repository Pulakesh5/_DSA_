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
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*> stk;
        ListNode *ans = nullptr, *newNode;
        while(head)
        {
            stk.push(head);
            head = head->next;
        }
        int div, carry=0;
        while(!stk.empty())
        {
            div = (2*stk.top()->val+carry);
            stk.pop();
            carry = div/10;
            div = div%10;
            ans = new ListNode(div, ans);
        }
        if(carry)
            ans = new ListNode(carry, ans);
        return ans;
    }
};
