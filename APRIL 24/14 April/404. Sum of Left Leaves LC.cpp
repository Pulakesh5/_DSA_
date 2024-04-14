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
    void sum_of_left_leaves(TreeNode* root, int direction, int &sum)
    {
        if(root==nullptr)
            return;
        if(direction==0 && root->left==nullptr && root->right==nullptr)
            sum+=(root->val);
        else
        {
            sum_of_left_leaves(root->left, 0, sum);
            sum_of_left_leaves(root->right, 1, sum);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        sum_of_left_leaves(root, -1, sum);
        return sum;
    }
};
