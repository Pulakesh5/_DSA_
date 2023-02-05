    int intersectPoint(Node* head1, Node* head2)
    {
        
        Node *root1=head1, *root2=head2;
        int len1=0, len2=0;
        
        while(root1 && ++len1)
            root1=root1->next;
        while(root2 && ++len2)
            root2=root2->next;
            
        if(len1<len2)
        {
            swap(len1,len2);
            swap(head1, head2);
        }
        root1=head1;
        root2=head2;
        
        while(len1>len2)
        {
            root1=root1->next;
            len1--;
        }
        
        while(root1!=root2)
        {
            root1=root1->next;
            root2=root2->next;
        }
        return root1->data;
    }
