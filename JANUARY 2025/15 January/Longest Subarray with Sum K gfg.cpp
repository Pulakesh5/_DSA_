class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<long long, long long> mp;
        mp[0] = -1;
        long long n = arr.size(), sum = 0;
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            if(mp.find(sum-k)!=mp.end())
            {
                ans = max(ans, i-mp[sum-k]);
            }
            if(mp.find(sum)==mp.end())
            {
                mp[sum] = i;
            }
        }
        return ans;
    }
};
