class Solution {
  public:
    vector<long long> distributeCandies(int N, int K) {
        // code here
        int low = 0, high = (N/K)+1;
        long long ans = 0, turn, required;
        while(low<=high)
        {
            turn = (low+high)/2;
            required = check(K, turn);
            
            if(required<=N)
            {
                ans = max(turn, ans);
                low = turn + 1;
            }
            else
                high = turn - 1;
            // cout<<turn<<" : "<<required<<", "<<ans<<endl;
        }
        vector<long long> distribution(K, 1ll*((ans*(ans-1))/2)*K);
        for(int i=1; i<=K; i++)
        {
            // cout<<i<<" : "<<distribution[i-1]<<endl;
            distribution[i-1] += 1ll*ans*i;
            N -= distribution[i-1];
        }
        long long candies;
        for(int i=1; i<=K && N; i++)
        {
            candies = min(ans*K+i, 1ll*N);
            distribution[i-1]+=candies;
            N-=candies;
        }
        return distribution;
    }
private:
    long long check(int K, int turn)
    {
        long long candies = 1ll*K*turn;
        candies = (candies*(candies+1))/2;
        return candies;
        
    }
    // 1 2 3
    // 4 5 6
    // 7 8 9
};
