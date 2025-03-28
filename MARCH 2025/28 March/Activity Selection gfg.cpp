class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        vector<pair<int,int>> vp;
        for(int i=0; i<n; i++) {
            vp.push_back({start[i], finish[i]});
        }
        sort(vp.begin(), vp.end(), [](pair<int,int> a, pair<int,int>b) {
            if(a.second == b.second)
                return a.first<b.first;
            return a.second<b.second;
        });
        
        int prevEnd = vp[0].second;
        int activity = 1;
        for(int i=1; i<n; i++) {
            if(vp[i].first > prevEnd)
            {
                activity++;
                prevEnd = vp[i].second;
            }
        }
        return activity;
    }
};
