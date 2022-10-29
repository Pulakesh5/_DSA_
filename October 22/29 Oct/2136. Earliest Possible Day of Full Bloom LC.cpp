class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> vp;
        int n=plantTime.size();
        
        for(int i=0;i<n;i++)
        {
            vp.push_back({-1*growTime[i],plantTime[i]});
        }
        sort(vp.begin(),vp.end());
        int ans=0,total=0,totalPlant=0,totalGrow=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,total+vp[i].second-vp[i].first);
            total+=vp[i].second;
        }
        return ans;
    }
};
