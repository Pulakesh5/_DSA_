class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> pos(26,-1);
        int len = s.size();
        for(int i=0; i<len; i++)
        {
            if(pos[s[i]-'a']==-1)
                pos[s[i]-'a'] = i;
            else
                pos[s[i]-'a'] = -2;
        }
        int firstUnique = INT_MAX;
        for(int i=0; i<26; i++)
        {
            if(pos[i]>=0)
                firstUnique = min(firstUnique, pos[i]);
        }
        return (firstUnique==INT_MAX?-1:firstUnique);
    }
};
