class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26,0);
        string sortedString = "";
        for(char ch:s)
            count[ch-'a']++;

        for(char ch:order)
        {
            if(count[ch-'a'])
            {
                string subStr = string(count[ch-'a'], ch);
                sortedString+=subStr;
                count[ch-'a']=0;
            }
        }

        for(int i=0; i<26; i++)
        {
            if(count[i])
            {
                string subStr = string(count[i], (char)('a'+i));
                sortedString+=subStr;
                count[i] = 0;
            }
        }

        return sortedString;
    }
};
