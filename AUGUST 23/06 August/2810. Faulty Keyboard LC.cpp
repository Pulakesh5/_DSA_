class Solution {
public:
    string finalString(string s) {
        string final_string = "";
        for(char ch:s)
        {
            if(ch!='i')
            {
                final_string.push_back(ch);
                continue;
            }
            reverse(final_string.begin(), final_string.end());
        }
        return final_string;
    }
};
