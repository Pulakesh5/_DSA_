class Solution {
  public:
    int check(string &s, int index, set<string> &setOfWords, vector<int> &isOk) {
        int len = s.size();
        if(index>=len)
            return 1;
        
        if(isOk[index]!=-1)
            return isOk[index];
        
        string word = "";
        for(int i=index; i<len; i++) {
            word.push_back(s[i]);
            if(setOfWords.find(word) == setOfWords.end())
                continue;
            
            if(check(s, i+1, setOfWords, isOk))
                return isOk[index] = 1;
        }
        return isOk[index] = 0;
    }
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        int N = s.size();
        vector<int> isOk(N+5, -1);
        set<string> setOfWords(dictionary.begin(), dictionary.end());
        return check(s, 0, setOfWords, isOk);
    }
};
