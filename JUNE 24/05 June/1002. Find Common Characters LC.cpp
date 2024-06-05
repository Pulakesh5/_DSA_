class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int wordCount = words.size();
        vector<int> intersection(26,0);
        for(char ch:words[0])
        {
            intersection[ch-'a']++;
        }
        for(int i=1; i<wordCount; i++)
        {
            vector<int> count(26,0);
            for(char ch:words[i])
                count[ch-'a']++;
            
            for(int i=0; i<26; i++)
                intersection[i] = min(intersection[i], count[i]);
        }

        vector<string> commonChar;
        for(int i=0; i<26; i++)
        {
            if(intersection[i]==0)
                continue;
            char ch = 'a'+i;
            string str(1,ch);
            for(int j=0; j<intersection[i]; j++)
                commonChar.push_back(str);
        }
        return commonChar;
    }
};
