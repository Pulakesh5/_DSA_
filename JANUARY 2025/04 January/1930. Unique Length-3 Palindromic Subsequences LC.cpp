class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26,-1), last(26,-1);
        int N = s.size(), ch;
        for(int i=0; i<N; i++)
        {
            ch = s[i]-'a';
            if(first[ch]==-1)
                first[ch] = i;
            last[ch] = i;
        }
        int count = 0;
        for(int i=0; i<26; i++)
        {
            if(first[i] < last[i])
                count += unordered_set<char>(s.begin()+first[i]+1, s.begin()+last[i]).size();
        }
        return count;
    }
};
