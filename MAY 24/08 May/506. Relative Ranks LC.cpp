class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int len = score.size();
        vector<pair<int,int>> vp(len);
        for(int i=0; i<len; i++)
        {
            vp[i] = {score[i],i};
        }
        sort(vp.begin(), vp.end(), greater<pair<int,int>>());
        vector<string> ranks(len);

        for(int i=0; i<len; i++)
        {
            if(i==0)
                ranks[vp[i].second] = "Gold Medal";
            else if(i==1)
                ranks[vp[i].second] = "Silver Medal";
            else if(i==2)
                ranks[vp[i].second] = "Bronze Medal";
            else 
                ranks[vp[i].second] = to_string(i+1);
        }
        return ranks;
    }
};
