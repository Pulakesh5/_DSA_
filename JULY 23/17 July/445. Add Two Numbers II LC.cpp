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
    ListNode* createLL(vector<int> sumDigits)
    {
        int len = sumDigits.size();
        ListNode *root = new ListNode(sumDigits[0]), *head;
        head = root;
        for(int i=1; i<len; i++)
        {
            head->next = new ListNode(sumDigits[i]);
            head = head->next;
        }
        return root;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> num1, num2, sumDigits;
        while(l1)
        {
            num1.push_back(l1->val);
            l1 = l1 -> next;
        }
        while(l2)
        {
            num2.push_back(l2->val);
            l2 = l2 -> next;
        }
        int p1 = num1.size() - 1, p2 = num2.size() - 1;
        int sum, carry = 0;
        while(p1>=0 && p2>=0)
        {
            sum = (carry+num1[p1--]+num2[p2--]);
            carry = sum/10;
            sumDigits.push_back(sum%10);
        }
        while(p1>=0)
        {
            sum = (carry+num1[p1--]);
            carry = sum/10;
            sumDigits.push_back(sum%10);
        }
        while(p2>=0)
        {
            sum = (carry+num2[p2--]);
            carry = sum/10;
            sumDigits.push_back(sum%10);
        }
        if(carry)
            sumDigits.push_back(carry);
        reverse(sumDigits.begin(), sumDigits.end());
        return createLL(sumDigits);
    }
};
