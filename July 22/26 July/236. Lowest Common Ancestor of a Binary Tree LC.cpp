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
private:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        
        if(root==p || root==q) return root;
        
        TreeNode* leftSubTree = LCA(root->left,p,q);
        TreeNode* rightSubTree = LCA(root->right,p,q);
        if(!leftSubTree) return rightSubTree;
        if(!rightSubTree) return leftSubTree;
        
        return root;
    }
};
