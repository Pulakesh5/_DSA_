class Solution{
  public:
    int MOD = 1e9+7;
    void dfs(Node *root, long long pathSum, long long target, unordered_map<int,int> &countPath, long long &ans)
    {
        if(!root)
            return;
        pathSum+=root->data;
        ans = (ans+countPath[pathSum-target])%MOD;
        countPath[pathSum]++;
        dfs(root->left, pathSum, target, countPath, ans);
        dfs(root->right, pathSum, target, countPath, ans);
        countPath[pathSum]--;
    }
    int sumK(Node *root,int k)
    {
        // code here 
        unordered_map<int, int> countPath;
        long long pathSum=0, target=k, ans=0;
        countPath[0] = 1;
        dfs(root, pathSum, target, countPath, ans);
        return ans;
    }
};
