class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for(int num:nums)
            strs.push_back(to_string(num));
        sort(begin(strs), end(strs), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        string result = "";
        for(auto str:strs)
        {
            result+=str;
        }
        while(result[0]=='0' && result.size()>1)
            result.erase(0,1);
        return result;
    }
};
