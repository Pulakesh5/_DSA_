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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==nullptr)
            return nullptr;
        TreeNode* lTree = removeLeafNodes(root->left, target);
        TreeNode* rTree = removeLeafNodes(root->right, target);
        
        if(lTree==nullptr && rTree==nullptr && root->val==target)
            return nullptr;
        root->left = lTree;
        root->right = rTree;
        return root;
    }
};
