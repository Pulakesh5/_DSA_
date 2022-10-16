    ListNode *moveToFront(ListNode *head){
        if(!head || !(head->next)) return head;
        int curr,last;
        last=head->val;
        ListNode *root=head;
        while(root)
        {
            curr=root->val;
            root->val=last;
            last=curr;
            root=root->next;
        }
        head->val=last;
        return head;
        
    }
