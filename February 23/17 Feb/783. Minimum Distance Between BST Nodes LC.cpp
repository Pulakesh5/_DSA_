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
    int minDiffInBST(TreeNode* root) {
        vector<int> traversal;
        traverse(root, traversal);
        int minDiff=INT_MAX;
        int n=traversal.size();
        for(int i=1;i<n;i++)
        {
            minDiff=min(minDiff,traversal[i]-traversal[i-1]);
        }
        return minDiff;
    }
    
    void traverse(TreeNode* root, vector<int> &traversal)
    {
        if(!root) return;
        traverse(root->left, traversal);
        traversal.push_back(root->val);
        traverse(root->right, traversal);
    }
};
