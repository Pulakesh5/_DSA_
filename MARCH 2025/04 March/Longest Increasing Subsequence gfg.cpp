class Solution {
  public:
    int lis(vector<int>& arr) {
        // code here
        int N = arr.size();
        vector<int> LIS(N);
        int ans = 1;
        for(int i=0; i<N; i++)
        {
            for(int j=i-1; j>-1; j--)
            {
                if(arr[j]<arr[i] && LIS[i]<LIS[j])
                    LIS[i] = LIS[j];
            }
            LIS[i]+=1;
            if(LIS[i]>ans)
                ans = LIS[i];
        }
        return ans;
    }
};
