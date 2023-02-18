class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode *lptr=invertTree(root->left);
        TreeNode *rptr=invertTree(root->right);
        root->left=rptr;
        root->right=lptr;
        return root;

    }
};
