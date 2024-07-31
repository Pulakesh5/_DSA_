class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        reverse(books.begin(), books.end());
        int N = books.size();
        int remainingSpace = shelfWidth;
        vector<int> dp(N+1);
        for(int i=0; i<N; i++)
        {
            dp[i+1] = dp[i] + books[i][1];
            int totalWidth = 0, maxHeight = 0;
            for(int j=i; j>=0; j--)
            {
                totalWidth += books[j][0];
                if(totalWidth>shelfWidth)
                {
                    break;
                }
                else
                {
                    maxHeight = max(maxHeight, books[j][1]);
                    dp[i+1] = min(dp[j]+maxHeight, dp[i+1]);
                }
            }
        }
        return dp[N];
    }
};
