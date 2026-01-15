class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hMax=2, vMax=2;
        int count=2;
        for(int i=1; i<hBars.size(); i++) {
            count = (hBars[i]==hBars[i-1]+1) ? count+1: 2;
            hMax = max(hMax, count);
        }
        count = 2;
        for(int i=1; i<vBars.size(); i++) {
            count = (vBars[i]==vBars[i-1]+1) ? count+1: 2;
            vMax = max(vMax, count);
        }

        return min(hMax,vMax)*min(hMax,vMax);
    }
};
