class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)  return 0;
        int right=minDepth(root->right);
        int left=minDepth(root->left);
        return (right==0 || left==0) ?left+right+1: 1+min(left,right);
    }
};
