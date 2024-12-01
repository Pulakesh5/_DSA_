class Solution {
  public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Your code here
        vector<int> firstPos(26,-1);
        int N = s.size();
        for(int i=0; i<N; i++)
        {
            if(firstPos[s[i]-'a']==-1)
                firstPos[s[i]-'a'] = i;
            else
                firstPos[s[i]-'a'] = INT_MAX;
        }
        int nonRepeating = N+1;
        for(int i=0; i<26; i++)
        {
            if(firstPos[i]==-1 || firstPos[i]==INT_MAX)
                continue;
            nonRepeating = min(nonRepeating, firstPos[i]);
        }
        if(nonRepeating==N+1)
            return '$';
        return s[nonRepeating];
    }
};
