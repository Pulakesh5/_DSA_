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
    void traverse(TreeNode* left, TreeNode* right, int odd)
    {
        if(left == nullptr && right == nullptr)
            return;
        if(odd)
            swap(left->val, right->val);
        traverse(left->left, right->right, 1-odd);
        traverse(left->right, right->left, 1-odd);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        traverse(root->left, root->right, 1);
        return root;
    }
};
