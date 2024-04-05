class Solution {
public:
    string makeGood(string s) {
        string goodString = "";
        for(char ch:s)
        {
            if(goodString.size()==0)
                goodString.push_back(ch);
            else if(ch>='a' && ch<='z')
            {
                char prevChar = goodString.back();
                if(prevChar>='A' && prevChar<='Z' && (ch-'a')==(prevChar-'A'))
                    goodString.pop_back();
                else
                    goodString.push_back(ch);
            }
            else
            {
                char prevChar = goodString.back();
                if(prevChar>='a' && prevChar<='z' && (ch-'A')==(prevChar-'a'))
                    goodString.pop_back();
                else
                    goodString.push_back(ch);
            }
        }
        return goodString;
    }
};
