class Solution {
public:
    string makeFancyString(string s) {
        string fancyString = "";
        for(char ch:s)
        {
            if(fancyString.size()<2)
                fancyString.push_back(ch);
            else
            {
                int currLen = fancyString.size();
                if(ch==fancyString[currLen-1] && ch==fancyString[currLen-2])
                    continue;
                fancyString.push_back(ch);
            }
        }
        return fancyString;
    }
};
