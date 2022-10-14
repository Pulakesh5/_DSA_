class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int count=0;
        ListNode* root=head;
        while(root)
        {
            count++;
            root=root->next;
        }
        if(count==1) return NULL;
        else if(count==2){
            head->next=NULL;
            return head;
        }

        int i=0;
        root=head;
        while(++i<(count/2))
            root=root->next;
        root->next=root->next->next;
        return head;
        
    }
};
