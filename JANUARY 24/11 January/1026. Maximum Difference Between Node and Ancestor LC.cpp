/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDiff=0;
    void dfs(TreeNode* root, int ancMax, int ancMin)
    {
        if(!root)
            return;
        // cout<<abs(ancMax-root->val)<<" "<<maxDiff<<endl;
        maxDiff = max(abs(ancMax-root->val), maxDiff);
        maxDiff = max(abs(ancMin-root->val), maxDiff);
        dfs(root->left, max(ancMax,root->val), min(ancMin,root->val));
        dfs(root->right, max(ancMax,root->val), min(ancMin,root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root || (!root->left && !root->right))
            return 0;
        dfs(root->left, root->val, root->val);
        dfs(root->right, root->val, root->val);
        return maxDiff;
    }
};
