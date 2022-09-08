class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        inorder(root, traversal);
        return traversal;
    }
    void inorder(TreeNode* root, vector<int> &traversal)
    {
        if(!root) return;
        inorder(root->left, traversal);
        traversal.push_back(root->val);
        inorder(root->right, traversal);
    }
};
