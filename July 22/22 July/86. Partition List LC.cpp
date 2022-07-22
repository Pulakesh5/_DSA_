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

/*********************************************************************************/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode* root=head;
        ListNode greatereq(0),lesser(0);
        ListNode *g=&greatereq,*l=&lesser;
        //ListNode *ref;
        
        while(root){
            ListNode* & ref = root->val < x ? l : g;
            ref->next=root;
            ref=ref->next;
            root=root->next;
        }
        l->next = greatereq.next;
        g->next=NULL;
        return lesser.next;
        
    }
};
