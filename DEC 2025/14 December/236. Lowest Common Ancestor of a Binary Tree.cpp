class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr || root==p || root==q)
            return root;

        TreeNode* ltree = lowestCommonAncestor(root->left, p, q);
        TreeNode* rtree = lowestCommonAncestor(root->right, p, q);
        
        if(ltree != nullptr && rtree != nullptr)
            return root;

        if(ltree == nullptr)
            return rtree;
        return ltree;
    }
};
