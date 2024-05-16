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
    bool evaluateTree(TreeNode* root) {
        if(root==nullptr)
            return true;
        int val = root->val;
        bool lTree = evaluateTree(root->left);
        bool rTree = evaluateTree(root->right);
        if(val<=1)
            return val;
        else if(val==2)
            return (lTree || rTree);
        else
            return (lTree && rTree);
    }
};
