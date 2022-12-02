class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.size()!=word2.size()) return false;
        
        vector<int> count1(26,0), count2(26,0);

        for(int i=0;i<word1.size();i++)
        {
            count1[word1[i]-'a']++;
            count2[word2[i]-'a']++;
        }
        
        sort(count1.rbegin(),count1.rend());
        sort(count2.rbegin(),count2.rend());

        if(set(word1.begin(),word1.end()) != set(word2.begin(),word2.end()))
            return false;
        
        for(int i=0;i<26;i++)
        {
            if(count1[i]!=count2[i])
                return false;
        }
        
        return true;

    }
};
