class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1="",str2="";
        for(string word:word1)
            str1+=word;
        for(string word:word2)
            str2+=word;
        return str1==str2;
    }
};
