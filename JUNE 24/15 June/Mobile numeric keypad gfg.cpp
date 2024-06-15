class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        if(n==1)
            return 10;
        else if(n==2)
            return 36;
        map<int,vector<long long>> next;
        next[0] = {0, 8};
        next[1] = {1, 2, 4};
        next[2] = {1, 2, 3, 5};
        next[3] = {2, 3, 6};
        next[4] = {1, 4, 5, 7};
        next[5] = {2, 4, 5, 6, 8};
        next[6] = {3, 5, 6, 9};
        next[7] = {4, 7, 8};
        next[8] = {0, 5, 7, 8, 9};
        next[9] = {6, 8, 9};
        vector<long long> dp(10,0), prev(10,1);
        for(int i=2; i<=n; i++)
        {
            for(int digit=0; digit<10; digit++)
            {
                // cout<<digit<<" :\n";
                dp[digit] = 0;
                for(auto key:next[digit])
                {
                    dp[digit] += prev[key];
                    // cout<<key<<", "<<dp[key]<<" ";
                }
                // cout<<endl;
            }
            
            // for(int digit=0; digit<10; digit++)
            //     cout<<dp[digit]<<" ";
            // cout<<endl;
            prev = dp;
        }
        long long count=0;
        for(int digit=0; digit<10; digit++)
            count+=dp[digit];
        return count;
    }
};
