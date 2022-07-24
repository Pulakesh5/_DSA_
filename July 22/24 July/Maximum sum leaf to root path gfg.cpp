class Solution{
    public:
    int maxPathSum(Node* root)
    {
        if(!root) return 0;
        return root->data+max(maxPathSum(root->right), maxPathSum(root->left));
    }
};
