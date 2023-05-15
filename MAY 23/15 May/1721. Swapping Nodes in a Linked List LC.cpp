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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head) return head;
        ListNode* ptr=head;
        int count=0;
        while(head){
            count++;
            head=head->next;
        }
        ListNode *ptr1=ptr,*ptr2=ptr;
        int iterator=1;
        while(iterator<k){
            iterator++;
            ptr1=ptr1->next;
        }
        iterator=0;
        while(iterator<(count-k)){
            iterator++;
            ptr2=ptr2->next;
        }
        int temp=ptr1->val;
        ptr1->val=ptr2->val;
        ptr2->val=temp;
        return ptr;
    }
};
