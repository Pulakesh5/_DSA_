    Node* sortList(Node* head)
    {
        // Your Code Here
        Node* root=head;
        vector<int> v;
        while(root)
        {
            v.push_back(root->data);
            root=root->next;
        }
        sort(v.begin(),v.end());
        root=head;
        for(int it:v)
        {
            root->data=it;
            root=root->next;
        }
        return head;
    }
