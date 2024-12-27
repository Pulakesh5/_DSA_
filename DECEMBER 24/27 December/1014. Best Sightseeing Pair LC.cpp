class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // score = val[i]+val[j] + i-j
        // => score = (val[i] + i) + (val[j] - j)
        int N = values.size();
        int mxPair = values[N-1]-N+1;
        int mxScore = INT_MIN;
        for(int i=N-2; i>=0; i--)
        {
            if(values[i]+i+mxPair > mxScore)
                mxScore = values[i] + i + mxPair;
            if(values[i]-i > mxPair)
                mxPair = values[i]-i;
        }
        return mxScore;
    }
};
