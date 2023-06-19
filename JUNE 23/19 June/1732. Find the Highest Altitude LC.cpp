class Solution {
public:
    int largestAltitude(vector<int>& gains) {
        long long highestAltitude = 0, height = 0;
        for(int gain:gains)
        {
            height+=gain;
            highestAltitude = max(highestAltitude, height);
        }
        return highestAltitude;
    }
};
