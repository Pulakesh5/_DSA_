class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> time;
        for(string timePoint:timePoints)
        {
            int hr = stoi(timePoint.substr(0,2));
            int minute = stoi(timePoint.substr(3,2));
            time.push_back(hr*60+minute);
        }
        sort(time.begin(), time.end());
        int N = timePoints.size(), minTimeDiff = 720;
        for(int i=1; i<N; i++)
        {
            minTimeDiff = min(minTimeDiff, time[i]-time[i-1]);
        }
        minTimeDiff = min(minTimeDiff, 1440-time[N-1]+time[0]);
        return minTimeDiff;
    }
};
