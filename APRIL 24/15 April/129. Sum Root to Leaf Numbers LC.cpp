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
    void sumRootToLeaf(TreeNode* root, long long &sum, int prev)
    {
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right==nullptr)
        {
            sum += (prev*10+root->val);
        }
        if(root->left)
            sumRootToLeaf(root->left, sum, prev*10+root->val);
        if(root->right)
            sumRootToLeaf(root->right, sum, prev*10+root->val);
    }
    int sumNumbers(TreeNode* root) {
        if(root->left==nullptr && root->right==nullptr)
            return root->val;
        long long sum = 0;
        sumRootToLeaf(root, sum, 0);
        return sum;
    }
};
