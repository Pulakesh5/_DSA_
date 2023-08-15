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
    ListNode* partition(ListNode* head, int x) {
        ListNode *l = new ListNode(0), *ge = new ListNode(0), *root = head;
        ListNode *Head = l, *geHead = ge;
        while(root)
        {
            if(root->val<x)
            {
                l->next = root;//new ListNode(root->val);
                l = l->next;
            }
            else
            {
                ge->next = root;//new ListNode(root->val);
                ge = ge->next;
            }
            root = root->next;
        }
        l -> next = geHead->next;
        ge->next = NULL;
        return Head->next;
    }
};
