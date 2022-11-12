	int vecmax(vector<int> &a) {
        int res = a[0];
        for (int i = 1; i < a.size(); i++)
            res = max(res, a[i]);
        return res;
    }
	public:
	int characterReplacement(string s, int k){
        // Code here
        vector<int> dp(26, 0);
        int i = 0, j = 0, res = 0;
        int tot = 0, n = s.size();
        while (j < n) {
            dp[s[j] - 'A']++;
            if (j - i + 1 - vecmax(dp) > k) {
                dp[s[i] - 'A']--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
	}
