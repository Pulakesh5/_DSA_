class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> allowed_char(26);
        
        for(char ch:allowed)
            allowed_char[ch-'a'] = true;
        
        int consistent = words.size();

        for(string word:words)
        {
            for(char ch:word)
            {
                if(!allowed_char[ch-'a'])
                {
                    consistent--;
                    break;
                }
            }
        }
        return consistent;
    }
};
