class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node* makeBST(vector<int> &traversal, int l, int r)
    {
        if(l>r)
            return nullptr;
        int rootIndex = (l+r)/2;
        Node* root = new Node(traversal[rootIndex]);
        root->left = makeBST(traversal, l, rootIndex-1);
        root->right = makeBST(traversal, rootIndex+1, r);
        return root;
    }
    void traverse(vector<int> &traversal, Node* root)
    {
        if(!root)
            return;
        traverse(traversal, root->left);
        traversal.push_back(root->data);
        traverse(traversal, root->right);
    }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> traversal;
        traverse(traversal, root);
        sort(traversal.begin(), traversal.end());
        return makeBST(traversal, 0, traversal.size()-1);
    }
};
