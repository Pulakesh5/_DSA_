    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> vp;
        
        if(!head) return vp;
        
        Node *p1=head,*p2=head;
        Node *root=head;
        while(root->next)
        {
            root=root->next;
            p2=p2->next;
        }
        
        long long sum=0;
        while(p1->data < p2->data)
        {
            sum=p1->data+p2->data;
            if(sum==target)
            {
                vp.push_back({p1->data,p2->data});
                p1=p1->next;
            }
            else if(sum < target)
                p1=p1->next;
            else
                p2=p2->prev;
        }
        
        return vp;
    }
};
