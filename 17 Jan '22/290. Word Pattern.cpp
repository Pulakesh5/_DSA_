/*
    Solution is easy, Use hashmap but think about how you would maintain the integrity of 
    char to word mapping?
*/
class Solution {
public:
    bool wordPattern(string pattern,string str) {
        int n=pattern.length();
        unordered_map<char , int> chartoint;
        unordered_map<string, int> wordtoint;
        istringstream stream(str);
        string word;
        int i=0;
        for(word; stream>>word; i++){
            if(i==n || chartoint[pattern[i]]!=wordtoint[word])
                return false;
            chartoint[pattern[i]] = wordtoint[word] = i+1;
        }
        return i==n;
        
    }
};
