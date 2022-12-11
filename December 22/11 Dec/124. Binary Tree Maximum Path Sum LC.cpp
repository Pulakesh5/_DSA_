class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSumPath=INT_MIN;
        
        DFS(root,maxSumPath);

        return maxSumPath;
    }

    int DFS(TreeNode *root, int &maxSumPath)
    {
        if(!root) return 0;
        int left = max( 0, DFS(root->left, maxSumPath));
        int right = max( 0, DFS(root->right, maxSumPath));

        maxSumPath=max(maxSumPath, left + right +root->val);

        return max(left,right) + root->val;
    }
};
