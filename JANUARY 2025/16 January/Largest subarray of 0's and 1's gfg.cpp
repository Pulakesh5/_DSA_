class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        map<int,int> mp;
        mp[0] = -1;
        int sum = 0, n = arr.size(), ans = 0;
        for(int i=0; i<n; i++)
        {
            sum += (arr[i]==0);
            sum -= (arr[i]==1);
            if(mp.find(sum)!=mp.end())
            {
                ans = max(ans, i-mp[sum]);
            }
            else
                mp[sum] = i;
        }
        return ans;
    }
};
