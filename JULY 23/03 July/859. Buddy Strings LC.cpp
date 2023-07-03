class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int len1 = s.size(), len2 = goal.size();
        if(s.size() != goal.size())
            return false;
        int ind1 = -1, ind2 = -1;
        vector<int> charCount(26, 0);
        for(int i=0; i<len1; i++)
        {
            charCount[s[i]-'a']++;
            if(s[i] == goal[i])
                continue;
            if(ind1==-1)
                ind1 = i;
            else if(ind1!=-1 && ind2 == -1)
                ind2 = i;
            else
                return false;
        }

        if(ind1!=-1 && ind2 != -1)
        {
            return goal[ind1]==s[ind2] && goal[ind2]==s[ind1];
        }
        if(ind1!=-1&& ind2==-1)
            return false;
        for(int i=0; i<26; i++)
            if(charCount[i]>1)
                return true;
        return false;
    }
};
