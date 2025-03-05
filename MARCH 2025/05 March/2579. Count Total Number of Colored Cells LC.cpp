class Solution {
public:
    long long coloredCells(int n) {
        return 1ll*n*n + 1ll*(n-1)*(n-1);
    }
};
