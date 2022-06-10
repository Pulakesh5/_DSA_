class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        vector<pair<int,int>> vp(N);
        for(int i=0;i<N;i++)
            vp[i]={B[i],A[i]};
        
        sort(vp.begin(), vp.end());
        reverse(vp.begin(),vp.end());
        int capacity=T,quantity=0;
        int ans=0;
        for(int i=0;i<N && capacity;i++){
            quantity=min(vp[i].second,capacity);
            //cout<<quantity<<" "<<(vp[i].first)<<'\n';
            ans+=(quantity*(vp[i].first));
            capacity-=quantity;
        }
        
        return ans;
    }
};
