class Solution {
  public:
    int sumK(Node *root, int k) {
        // code here
        
        mp[0] = 1;
        solve(root, k, 0);
        return answer;
    }
    private:
    int answer = 0;
    const int MOD = 1e9+7;
    unordered_map<int,int> mp;
    void solve(Node *root, int k, int sum)
    {
        if(root == nullptr)
            return;
        sum += root->data;
        
        if(mp.find(sum-k)!=mp.end())
            answer = (answer+mp[sum-k])%MOD;
        
        mp[sum]++;
        solve(root->left, k, sum);
        solve(root->right, k, sum);
        mp[sum]--;
        if(mp[sum]==0)
            mp.erase(sum);
    }
};
