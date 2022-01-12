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
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        rec(root,sum,0);
        return sum;
    }
    void rec(TreeNode *root, int &sum, int cur){
        cur*=2;
        cur+= root->val;
        if(!root->right && !root->left) sum+=cur;
        else{
            if(root->right) rec(root->right,sum,cur);
            if(root->left) rec(root->left,sum,cur);
        }
    }
        
};
