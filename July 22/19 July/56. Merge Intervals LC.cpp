class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1]<b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        int start=intervals[0][0],end=intervals[0][1];
        
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end)
                end=max(end,intervals[i][1]);
            else{
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
