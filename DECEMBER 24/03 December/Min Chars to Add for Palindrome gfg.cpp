class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        int Length = s.size();
        vector<int> dp(Length);
        string rev = s;
        reverse(rev.begin(), rev.end());
        string merged = s + "$" + rev;
        int mergedLength = merged.size();
        vector<int> lps(mergedLength);
        for(int i=1; i<mergedLength; i++)
        {
            int len = lps[i-1];
            while(len>0 && merged[i]!=merged[len])
                len = lps[len-1];
            
            if(merged[i] == merged[len])
                len++;
            lps[i] = len;
        }
        return Length - lps[mergedLength-1];
    }
};
