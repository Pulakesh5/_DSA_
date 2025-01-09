class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int countOfPrefix = 0;
        int k = pref.size();
        for(string word:words)
        {
            if(word.size()<k || word[0]!=pref[0])
                continue;
            int match = 1;
            for(int j=0; j<k; j++)
            {
                if(word[j]!=pref[j])
                {
                    match = 0;
                    break;
                }
            }
            countOfPrefix += match;
        }
        return countOfPrefix;
    }
};
