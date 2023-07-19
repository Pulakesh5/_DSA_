class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){return a[1] < b[1];});
        
        int lastEnding = INT_MIN, intervalRemoved = 0;

        for(vector<int> interval:intervals)
        {
            if(interval[0]<lastEnding)
                intervalRemoved++;
            else
                lastEnding = interval[1];
        }
        return intervalRemoved;
    }
};
