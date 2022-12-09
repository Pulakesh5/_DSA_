class Solution {
public:

    int maxAncestorDiff(TreeNode* root) {
        int mx=INT_MIN, mn=INT_MAX;

        return process(root, mx, mn); //return value {min value, max value}
    }

    int process(TreeNode *root, int mx, int mn)
    {
        if(!root) return 0;

        mx=max(mx,root->val);
        mn=min(mn,root->val);

        return (root->left == root->right) ? (mx-mn) : max( process(root->left, mx, mn), process(root->right,mx,mn));
    }
};
