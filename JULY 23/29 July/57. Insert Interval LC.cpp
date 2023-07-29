class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> mergedIntervals;
        int len = intervals.size();
        bool inserted = false;
        for(int i=0; i<len; i++)
        {
            vector<int> interval = intervals[i];
            if(interval[1]<newInterval[0])
                mergedIntervals.push_back(interval);
            else if(interval[0]>newInterval[1])
            {
                mergedIntervals.push_back(newInterval);
                newInterval = interval;
            }
            else
            {
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
        }
        
        mergedIntervals.push_back(newInterval);
        
        return mergedIntervals;
    }
};
