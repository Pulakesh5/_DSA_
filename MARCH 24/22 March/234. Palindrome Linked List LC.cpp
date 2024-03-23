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
    bool isPalindrome(ListNode* head) {
        ListNode* root = head;
        string pattern = "";
        while(head)
        {
            pattern.push_back(head->val+'0');
            head = head->next;
        }
        int lptr = 0, rptr = pattern.size()-1;
        while(lptr<rptr)
        {
            if(pattern[lptr]!=pattern[rptr])
                return false;
            lptr++;
            rptr--;
        }
        return true;
    }
};
