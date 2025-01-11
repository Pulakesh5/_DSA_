class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        vector<int> lastPos(26, -1);
        int N = s.size(), last = 0;
        int longestUniqueSubstrLength = 1;
        for(int i=0; i<N; i++)
        {
            if(lastPos[s[i]-'a']!=-1)
                last = max(lastPos[s[i]-'a']+1, last);
            lastPos[s[i]-'a'] = i;
            longestUniqueSubstrLength = max(longestUniqueSubstrLength, i-last+1);
            // cout<<i<<" "<<s[i]<<" last = "<<last<<", ans "<<longestUniqueSubstrLength<<endl;
        }
        return longestUniqueSubstrLength;
    }
};
