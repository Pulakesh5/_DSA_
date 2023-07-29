class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        return a[1]<b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> mergedIntervals;
        int lastEnd = intervals[0][1], lastStart = intervals[0][0];
        for(vector<int> interval:intervals)
        {
            if(lastEnd<interval[0])
            {
                mergedIntervals.push_back({lastStart, lastEnd});
                lastStart = interval[0];
                lastEnd = interval[1];
            }
            else
                lastEnd = max(lastEnd, interval[1]);
        }
        mergedIntervals.push_back({lastStart, lastEnd});

        return mergedIntervals;
    }
};
