class Solution {
  public:
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        
        int n=arr.size();
        vector<pair<int,int>> vp(n);
        for(int i=0;i<n;i++)
            vp[i]={arr[i][0],arr[i][1]};
        sort(vp.begin(), vp.end());
        int ans=0;
        for(int i=1;i<n;i++){
            if(vp[i].first==vp[i-1].first){
                ans = max(ans, __gcd(vp[i].second,vp[i-1].second));
            }
        }
        return ans;
    }
};
