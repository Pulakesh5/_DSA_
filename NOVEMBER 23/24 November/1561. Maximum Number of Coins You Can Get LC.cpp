class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int maxCoin = 0, len = piles.size();
        int n = len/3;
        for(int i=len-1; i>=n; i-=2)
            maxCoin += piles[i-1];
        return maxCoin;
    }
};

// 1 2 2 4 7 8

// 1 2 3 4 5 6 7 8 9
