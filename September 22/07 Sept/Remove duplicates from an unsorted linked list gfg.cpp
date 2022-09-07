    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
        unordered_map<int,bool> dup;
        Node* root=head;
        
        if(!(head->next)) return head;
        
        Node* node=head;
        dup[node->data]=true;
        
        while(node && node->next)
        {
            if(dup[node->next->data] == false)
            {
                dup[node->next->data]=true;
                node=node->next;
            }
            else
                node->next = node->next->next;
        }
        
        return root;
    }
