class Solution {
public:
    vector<vector<TreeNode*>> dp;
    vector<TreeNode*> makeTrees(int n)
    {
        TreeNode* root;
        if(n%2 == 0)
            return {};
        if(dp[n].size()!=0)
            return dp[n];
        if(n==1)
        {
            root = new TreeNode();
            return {root};
        }
        vector<TreeNode*> v, left, right;
        for(int i=1; i<n; i+=2)
        {
            left = makeTrees(i);
            right = makeTrees(n-1-i);

            for(TreeNode* l:left)
            {
                for(TreeNode* r:right)
                {
                    root = new TreeNode();

                    root->left = l;
                    root->right = r;

                    v.push_back(root);
                }
            }
        }
        return dp[n] = v;

    }
    vector<TreeNode*> allPossibleFBT(int n) {
        dp.resize(n+1);
        return makeTrees(n);
    }
};
