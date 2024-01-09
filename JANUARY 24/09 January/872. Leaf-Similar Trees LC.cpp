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
    void traverse(TreeNode* root1, vector<int> &v)
    {
        if(root1->left==nullptr && root1->right==nullptr)
        {
            v.push_back(root1->val);
            return;
        }
        if(root1->left) 
            traverse(root1->left, v);
        if(root1->right) 
            traverse(root1->right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2;
        traverse(root1, v1);
        traverse(root2, v2);      
        return v1==v2;
    }
};
