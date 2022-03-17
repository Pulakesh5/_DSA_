class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode *head1=l1,*head2=l2,*ans=head1;
        
        if(head1->val <= head2->val)
            head1=head1->next;
        else
        {
            ans=head2;
            head2=head2->next;
        }
        
        ListNode *ptr=ans;
        while(head1 && head2){
            if(head1->val < head2->val){
                ptr->next=head1;
                head1=head1->next;   
            }
            else{
                ptr->next=head2;
                head2=head2->next;
            }
            ptr=ptr->next;
        }
        if(!head2) ptr->next=head1;
        else ptr->next=head2;
        return ans;
    }
};
