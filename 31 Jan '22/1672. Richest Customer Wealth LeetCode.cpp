class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int wealth=0,ans=0;
        
        for(auto customer:accounts){
            wealth=0;
            for(auto amounts:customer){
                wealth+=amounts;
            }
            if(wealth>ans)
                ans=wealth;
        }
        
        return ans;
    }
};
