class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int,int>> timeStamp;
        for(vector<int> interval:intervals) {
            timeStamp.emplace_back(interval[0], 1);
            timeStamp.emplace_back(interval[1]+1, -1);
        }
        sort(timeStamp.begin(), timeStamp.end());
        int minGroup = 1, overlapping = 0;
        for(auto &[_, count]:timeStamp) {
            overlapping += count;
            minGroup = max(minGroup, overlapping);
        }   
        return minGroup;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
