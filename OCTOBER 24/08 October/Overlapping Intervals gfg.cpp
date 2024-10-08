class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        // Code here
        sort(intervals.begin(), intervals.end());
        vector<int> currInterval = intervals[0];
        int N = intervals.size();
        vector<vector<int>> overlappingIntervals;
        
        for (int i=1; i<N; i++) {
            if (intervals[i][0]<=currInterval[1]) {
                currInterval = {currInterval[0], max(currInterval[1], intervals[i][1])};
            } else {
               overlappingIntervals.push_back(currInterval);
               currInterval = intervals[i];
            }
        }
        overlappingIntervals.push_back(currInterval);
        return overlappingIntervals;
    }
};
