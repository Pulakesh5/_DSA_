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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        if(k==0) return head;
        int size=1;
        
        ListNode *ans=head,*ptr;
        while(ans->next){
            size++;
            ans=ans->next;
        }
        k=k%size;
        if(k==0) return head;
        ans->next=head;
        
        for(int i=0;i<(size-k);i++)
            ans=ans->next;
        ptr=ans->next;
        ans->next=NULL;
        
        return ptr;
    }
};
