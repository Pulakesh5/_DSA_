class Solution {
public:
    bool hasPath=false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        long long sum=0;
        dfs(root,sum,targetSum);
        return hasPath;
    }
    void dfs(TreeNode* root,long long &sum, int &targetSum)
    {
        if(!root) return;
        
        sum+=root->val;
        if(!(root->left) && !(root->right) && sum==targetSum)
        {
            hasPath=true;
            return;
        }
        dfs(root->left,sum,targetSum);
        if(!hasPath) dfs(root->right,sum,targetSum);

        sum-=(root->val);
    }
};
