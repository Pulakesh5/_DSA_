class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n+1,0),suf(n+2,0);
        
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+nums[i-1];
            suf[i]=suf[i-1]+nums[n-i];
        }
        int ans=INT_MIN,curr=0;
        for(int i=0;i<=k;i++){
            curr=pre[i]+suf[k-i];
            //cout<<"i "<<i<<" "<<"curr "<<curr<<" "<<ans<<endl;
            ans=max(ans,curr);
        }
        
        return ans;
    }
};
