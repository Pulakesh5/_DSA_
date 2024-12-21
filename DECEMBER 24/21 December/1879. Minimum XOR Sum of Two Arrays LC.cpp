class Solution {
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int index, int mask, vector<vector<int>> &dp)
    {
        if(index>=nums2.size())
            return 0;

        if(dp[index][mask]!=-1)
            return dp[index][mask];
        int N = nums1.size();
        int minXOR = INT_MAX, nextMask;
        for(int i=0; i<N; i++)
        {
            if(mask&(1<<i))
            {
                nextMask = mask & ~(1<<i);
                minXOR = min(minXOR, (nums1[index]^nums2[i]) + solve(nums1, nums2, index+1, nextMask, dp));
            }
        }
        // cout<<index<<" "<<mask<<" : "<<minXOR<<endl;
        return dp[index][mask] = minXOR;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int N = nums2.size();
        int allSubset = (1<<N);
        vector<vector<int>> dp(N, vector<int>(allSubset, -1));
        solve(nums1, nums2, 0, allSubset-1, dp);
        int ans = INT_MAX;
        
        for(int i=0; i<allSubset; i++)
        {
            if(dp[0][i]!=-1)
                ans = min(ans, dp[0][i]);
        }
        
        return ans;
    }
};
