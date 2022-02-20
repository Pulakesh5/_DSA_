class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]>b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), comp);
        
        int start=intervals[0][0],end=intervals[0][1];
        
        int n=intervals.size(),event=1;
        
        for(int i=1;i<n;i++){
            
            while(i<n && start<=intervals[i][0] && intervals[i][1]<=end)
                i++;
            
            if(i<n){
                event++;
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        
        return event;
    }
};
