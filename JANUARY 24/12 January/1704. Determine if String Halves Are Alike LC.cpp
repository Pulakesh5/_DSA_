class Solution {
public:
    bool halvesAreAlike(string s) {
        int unlike=0;
        int len=s.size();
        set<char> vowels={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i=0; i<(len/2); i++)
            unlike+=(vowels.find(s[i])!=vowels.end());
        for(int i=len/2; i<len; i++)
            unlike-=(vowels.find(s[i])!=vowels.end());
        return !unlike;
    }
};
