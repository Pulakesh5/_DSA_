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
    vector<vector<int>> paths;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return paths;
        int sum=0;
        vector<int> path;
        backtrack(path,sum,targetSum,root);
        return paths;
    }
    
    void backtrack(vector<int> &path, int &sum, int &targetSum, TreeNode* root)
    {
        if(!root) return;
        if((sum+root->val)==targetSum && !(root->left) && !(root->right))
        {
            path.push_back(root->val);
            paths.push_back(path);
            path.pop_back();
            return;
        }
        
        sum+=root->val;
        path.push_back(root->val);
        
        backtrack(path,sum,targetSum,root->left);
        backtrack(path,sum,targetSum,root->right);
        sum-=(root->val);
        path.pop_back();
    }
};
