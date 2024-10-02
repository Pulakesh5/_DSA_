class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int N = arr.size();
        if(N==0)
            return {};
        vector<pair<int,int>> vp(N);
        for (int i=0; i<N; i++) {
            vp[i] = {arr[i], i};
        }
        sort(vp.begin(), vp.end());
        int rank = 1;
        for (int i=0; i<(N-1); i++) {
            arr[vp[i].second] = rank;
            if(vp[i].first==vp[i+1].first)  
                continue;
            rank++;
        }
        arr[vp.back().second] = rank;
        return arr;
    }
};

static const auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
