class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int N = (n*(n+1))/2;
        vector<int> subSums(N);
        int k = 0;
        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum+=nums[j];
                subSums[k++] = sum;
            }
        }   
        
        sort(subSums.begin(), subSums.end());

        long long MOD = 1e9+7;
        int ans = 0;
        for(int i=left-1; i<right; i++)
            ans = (ans+subSums[i])%MOD;
        return ans;
    }
};
