class Solution {
public:
    int longestPalindrome(string s) {
        int len=0, oddCount=0;
        map<int, int> freq;
        for(char ch:s)
            freq[ch]++;
        
        for(auto it:freq)
        {
            len+=(2*(it.second/2));
            oddCount+=(it.second%2);
        }
        return len+(oddCount>0);
    }
};
