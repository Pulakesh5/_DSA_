class Solution {
  public:
    int smallestSubstring(string S) {
        int count[3]={0,0,0},ptr[3]={-1,-1,-1};
        int n=S.length();
        int ans=INT_MAX;
        bool flag=false;
        for(int i=0;i<n;i++){
            int d=S[i]-'0';
            count[d]++;
            ptr[d]=i;//max(ptr[d],i);
            if(count[0]>0 && count[1]>0 && count[2]>0){
                flag=true;
                ans=min(ans, max({ptr[0],ptr[1],ptr[2]}) - min({ptr[0],ptr[1],ptr[2]}) +1);
            }
        }
        if(flag)
            return ans;
        return -1;
    }
};
