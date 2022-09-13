    void convertToMaxHeapUtil(Node* &root)
    {
        vector<int> traversal;
        inorder(root,traversal);
        reverse(traversal.begin(),traversal.end());
        postorder(root,traversal);
    }    
    void postorder(Node* root, vector<int> &traversal)
    {
        if(!root) return;
        postorder(root->left,traversal);
        postorder(root->right,traversal);
        root->data=traversal.back();
        traversal.pop_back();
    }
    void inorder(Node* root, vector<int> &traversal)
    {
        if(!root) return;
        inorder(root->left,traversal);
        traversal.push_back(root->data);
        inorder(root->right,traversal);
    }
