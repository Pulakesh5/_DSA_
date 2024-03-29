    Node* merge(Node* head1,Node* head2){
        // if(!head1 && !head2) return nullptr;
        if(!head1) return head2;
        if(!head2) return head1;
        if(head1->data<=head2->data){
            head1->bottom=merge(head1->bottom,head2);
            return head1;
        }
        head2->bottom=merge(head2->bottom,head1);
        return head2;
    }
    Node *flatten(Node *root)
    {
        // Your code here
        if(root==nullptr || root->next==nullptr) return root;
        return merge(flatten(root->next),root);
    }
