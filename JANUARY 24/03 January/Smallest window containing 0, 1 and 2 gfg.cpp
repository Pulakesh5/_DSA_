class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int zero=-1, one=-1, two=-1;
        int len = S.size();
        int minLen = len+1;
        for(int i=0; i<len; i++)
        {
            if(S[i]=='0')
                zero=i;
            else if(S[i]=='1')
                one=i;
            else
                two = i;
            if(zero!=-1 && one!=-1 && two!=-1)
            {
                minLen = min(max({zero, one, two})-min({zero, one, two})+1, minLen);
            }
        }
        if(minLen==(len+1))
            return -1;
        return minLen;
    }
};
