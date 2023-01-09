class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> traversal;
        traverse(root,traversal);
        return traversal;
    }
    void traverse(TreeNode* root, vector<int> &traversal)
    {
        if(!root) return;
        traversal.push_back(root->val);
        traverse(root->left,traversal);
        traverse(root->right,traversal);
    }
};
