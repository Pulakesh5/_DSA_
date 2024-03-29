/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root,p,q);
    }
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return root;
        if(root->val==p->val || root->val==q->val) return root;
        if(root->val > p->val && root->val > q->val) return LCA(root->left,p,q);
        if(root->val < p->val && root->val < q->val) return LCA(root->right,p,q);
        //if(root->val > p->val && root->val < q->val)
        return  root;
        //LCA(root->left,p,q);
        
    }
};
