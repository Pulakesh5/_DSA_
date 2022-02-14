class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool flag= abs(height(root->left)-height(root->right))<=1; // flag for checking height difference
        return isBalanced(root->right)&&isBalanced(root->left) && flag; //recursively calling isBalanced
    }
    int height(TreeNode *root)    //height function to get maxDepth
    {
        if(!root) return 0;
        int left=height(root->left),right=height(root->right);
        //if(abs(left-right)>1) return INT_MAX;
        return 1+max(left,right);
    }
};
