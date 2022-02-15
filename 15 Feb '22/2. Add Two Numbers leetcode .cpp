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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1=l1,*t2=l2;
        int n1=0,n2=0;
        while(t1){
            t1=t1->next;n1++;
        }
        while(t2){
            t2=t2->next;n2++;
        }
        ListNode *temp;
        if(n1<n2){
            t1=l2;t2=l1;
        }
        else{
            t1=l1;t2=l2;
        }
        int carry=0,sum=0;
        int n=max(n1,n2);
        for(int i=0;i<n;i++){
            sum=0;
            if(t1)
                sum+=(t1->val);
            if(t2){
                sum+=(t2->val);
                t2=t2->next;
            }
            sum+=carry;
            carry=(sum/10);
            //cout<<carry<<" "<<sum<<'\n';
            t1->val=(sum%10);
            temp=t1;
            t1=t1->next;
        }
        if(carry){
            temp->next= new ListNode(carry);
            if(!temp) cout<<"NULL";
        }
        if(n1>=n2)
            return l1;
        return l2;
    }
};
