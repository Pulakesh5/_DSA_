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
    TreeNode* pruneTree(TreeNode* root) {
        int rootPrun=pruning(root);
        if(!rootPrun) return NULL;
        return root;
    }
    int pruning(TreeNode* root)
    {
        if(!root) return 0;
        int leftPrun=pruning(root->left);
        int rightPrun=pruning(root->right);
        
        if(!leftPrun) root->left=NULL;
        if(!rightPrun) root->right=NULL;
        
        return (leftPrun+rightPrun+root->val);
    }
};
