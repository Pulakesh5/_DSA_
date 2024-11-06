class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix = "";
        size_t len = strs.size();
        int index = 0;
        bool exit = 0;
        while(!exit)
        {
            if(index==strs[0].size())
            {
                exit = true;
                break;
            }
            char ch = strs[0][index];
            for(int i=1; i<len; i++)
            {
                if((strs[i].size()==index) || (strs[i][index]!=ch))
                {
                    exit = true;
                    break;
                }
            }
            if(!exit)
                commonPrefix.push_back(ch);
            index++;
        }
        return commonPrefix;
    }
};
