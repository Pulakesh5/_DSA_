class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> count(26);
        for(char ch:s)
            count[ch-'a']++;
        for(char ch:t)
            count[ch-'a']--;
        int minStep=0;
        for(int i=0; i<26; i++)
            minStep+=abs(count[i]);
        return minStep/2;
    }
};
