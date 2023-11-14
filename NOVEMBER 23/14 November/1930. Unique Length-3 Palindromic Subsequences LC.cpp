class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstPos(26,-1), lastPos(26,-1);
        int len=s.size();
        for(int i=0; i<len; i++)
        {
            if(firstPos[s[i]-'a']==-1)
                firstPos[s[i]-'a'] = i;
            lastPos[s[i]-'a'] = i;
        }

        int middle=0, pallindrome=0;
        for(int i=0; i<26; i++)
        {
            if(firstPos[i] < lastPos[i])
                pallindrome += unordered_set<char>(s.begin()+firstPos[i]+1, s.begin()+lastPos[i]).size();
                
        }
        return pallindrome;

    }
};
