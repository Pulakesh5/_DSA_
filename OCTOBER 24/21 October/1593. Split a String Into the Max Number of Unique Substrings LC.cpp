class Solution {
public:
    int maxCount = 1;
    int maxUniqueSplit(string s) {
        set<string> uniqueSubstrings;
        int count = 0;
        split(s, 0, uniqueSubstrings, count);
        return maxCount;
    }
    void split(string &s, int index, set<string> &uniques, int count) {
        int len = s.size();
        if(count+(len-index) <= maxCount)
            return;
        if(index >= len)
        {
            maxCount = max(maxCount, count);
            return;
        }
        string substring;
        for(int i=index; i<len; i++){
            substring = s.substr(index, i-index+1);
            if(uniques.find(substring)==uniques.end())
            {
                uniques.insert(substring);
                split(s, i+1, uniques, count+1);
                uniques.erase(uniques.find(substring));
            }
        }
    }
};
