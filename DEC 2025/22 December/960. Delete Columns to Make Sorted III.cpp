class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int nRow = strs.size(), nCol = strs[0].size();
        int k;
        vector<int> dp(nCol+1,1);
        int ans=nCol-1;
        for(int j=0; j<nCol; j++) {
            for(int i=0; i<j; i++) {
                for(k=0; k<nRow; k++) {
                    if(strs[k][i]>strs[k][j])
                        break;
                }
                if(k==nRow && dp[i]+1 > dp[j])
                    dp[j] = dp[i] + 1;
            }
            ans = min(ans, nCol-dp[j]);
        }
        return ans;
    }
};
