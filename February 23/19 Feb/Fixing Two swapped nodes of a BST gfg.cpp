    struct Node *correctBST(struct Node *root) {
        // code here
        vector<int> traversal;
        traverse(root,traversal);
        sort(traversal.begin(), traversal.end());
        reverseTraverse(root,traversal);
        return root;
    }
    
    void traverse(struct Node* root, vector<int> &traversal)
    {
        if(!root) return;
        traverse(root->left, traversal);
        traversal.push_back(root->data);
        traverse(root->right, traversal);
    }
    
    void reverseTraverse(struct Node* root, vector<int> &traversal)
    {
        if(!root) return;
        reverseTraverse(root->right, traversal);
        root->data=traversal.back();
        traversal.pop_back();
        reverseTraverse(root->left, traversal);
    }
