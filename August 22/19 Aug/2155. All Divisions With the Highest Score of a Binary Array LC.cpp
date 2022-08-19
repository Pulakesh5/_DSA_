class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n+2,0), suf(n+2,0);
        
        for(int i=0;i<n;i++) pre[i+1]=pre[i]+(1-nums[i]);
        pre[n+1]=pre[n];
        
        for(int i=n-1;i>=0;i--) suf[i+1]=suf[i+2]+nums[i];
        suf[0]=suf[1];
        
        int mx=0;
        
        for(int i=0;i<=n;i++){
            mx=max(mx,pre[i]+suf[i+1]);
        }
        vector<int> index;
        for(int i=0;i<=n;i++){
            if(mx==(pre[i]+suf[i+1]))
                index.push_back(i);
        }
        return index;
    }
};
