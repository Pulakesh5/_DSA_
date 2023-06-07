class Solution {
  public:
    int lim = 1e5+1;
    
    vector<int> leastPrimeFactor(int n) {
        vector<int> arr(n+1);
        for(int i=1; i<=n; i++)
            arr[i] = i;
        for(int i=2; i<=sqrt(n); i++)
        {
            if(arr[i]==i)
            {
                for(int j=i*i; j<=n; j+=i)
                {
                    if(arr[j]==j)
                        arr[j] = i;
                }
            }
        }

        vector<int> ans(n+1);
        for(int i=1; i<=n; i++) ans[i] = arr[i];
        return ans;
    }
};
