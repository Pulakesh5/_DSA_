class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        vector<int> charFreq(26, 0);
        for(char ch:s1)
            charFreq[ch-'a']++;
        for(char ch:s2)
            charFreq[ch-'a']--;
        for(int i=0; i<26; i++)
        {
            if(charFreq[i]!=0)
                return false;
        }
        return true;
    }
};
