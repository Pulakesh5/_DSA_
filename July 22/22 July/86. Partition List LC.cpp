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
        if(!head) return head;
        ListNode* root=head;
        queue<int> greatereq,lesser;
        while(root){
            if(root->val<x) lesser.push(root->val);
            else greatereq.push(root->val);
            root=root->next;
        }
        root=head;
        while(!lesser.empty() && root){
            root->val=lesser.front();
            lesser.pop();
            root=root->next;
        }
        while(!greatereq.empty() && root){
            root->val=greatereq.front();
            greatereq.pop();
            root=root->next;
        }
        return head;
    }
};
