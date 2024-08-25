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
    void traverse(TreeNode* root, vector<int> &traversal)
    {
        if(root==nullptr)
            return;
        traverse(root->left, traversal);
        traverse(root->right, traversal);
        traversal.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> traversal;
        traverse(root, traversal);
        return traversal;
    }
};
