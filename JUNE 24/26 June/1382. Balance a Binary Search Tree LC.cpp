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
private:
    TreeNode* balance(vector<int> &v, int l, int r)
    {
        if(l>r)
            return nullptr;
        int midIndex = (l+r+1)/2;
        TreeNode* root = new TreeNode(v[midIndex]);
        root->left = balance(v, l, midIndex-1);
        root->right = balance(v, midIndex+1, r);
        return root;
    }
    void traverse(TreeNode* root, vector<int> &v)
    {
        if(root == nullptr)
            return;
        traverse(root->left, v);
        v.push_back(root->val);
        traverse(root->right, v);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        traverse(root, v);
        return balance(v, 0, v.size()-1);   
    }
};
