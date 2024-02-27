class Solution {
public:
    int lDepth=0, rDepth=0;
    int findDepth(TreeNode* root, int &depth)
    {
        if(root==nullptr)
            return 0;
        int lTree = findDepth(root->left,depth);
        int rTree = findDepth(root->right,depth);
        depth = max(depth, lTree+rTree);
        return max(lTree, rTree)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findDepth(root,diameter);
        return diameter;
    }
};
