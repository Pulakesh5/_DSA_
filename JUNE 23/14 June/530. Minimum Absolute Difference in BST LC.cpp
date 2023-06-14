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
    int getMinimumDifference(TreeNode* root) {
        long long prev = INT_MIN, minDifference=INT_MAX;
        traverse(root, prev, minDifference);
        return minDifference;
    }

    void traverse(TreeNode* root, long long &prev, long long &minDifference)
    {
        if(!root)
            return;
        traverse(root->left, prev, minDifference);
        minDifference = min(minDifference, root->val - prev);
        prev = root->val;
        traverse(root->right, prev, minDifference);
    }
};
