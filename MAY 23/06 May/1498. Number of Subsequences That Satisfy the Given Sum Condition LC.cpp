class Solution {
public:
    long long mod = 1e9+7;
    int _pow(long long int num, int p)
    {
        long long res = 1;
        while(p>0)
        {
            if(p&1)
                res = (res * num) % mod;
            num = (num * num)%mod;
            p=p>>1;
        }
        return res;
    }
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long ans = 0, n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(2*nums[i]>target) continue;
            int nxt = lower_bound(nums.begin(), nums.end(), (target - nums[i] + 1)) - nums.begin();
            int count = nxt - i-1;
            // cout<<nums[i]<<" "<<nxt<<endl;
            ans = (ans + _pow(2,count))%mod;
        }
        return ans;
    }
};
