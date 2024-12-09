class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>> mergedIntervals;
        sort(arr.begin(), arr.end());
        int start = arr[0][0], lastEnding = arr[0][1], N = arr.size();
        for(int i=1; i<N; i++)
        {
            if(arr[i][0]<=lastEnding)
            {
                lastEnding = max(lastEnding, arr[i][1]);
            }
            else
            {
                mergedIntervals.push_back({start, lastEnding});
                start = arr[i][0];
                lastEnding = arr[i][1];
            }
        }
        mergedIntervals.push_back({start, lastEnding});
        return mergedIntervals;
    }
};
