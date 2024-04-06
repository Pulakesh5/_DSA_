class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string validString = "";
        int len = s.size(), unbalanced=0;
        for(int i=0; i<len; i++)
        {
            validString.push_back(s[i]);
            if(s[i]>='a' && s[i]<='z')
                continue;
            else if(s[i]=='(')
                unbalanced++;
            else if(s[i]==')')
                unbalanced--;
            if(unbalanced<0)
            {
                validString.pop_back();
                unbalanced=0;
            }
        }
        // cout<<validString<<" "<<unbalanced<<endl;
        int i = validString.size()-1;
        string lastPart="";
        while(i>=0 && unbalanced>0)
        {
            lastPart.push_back(validString[i]);
            i--;
            if((lastPart.back()>='a' && lastPart.back()<='z') || lastPart.back()==')')
                ;
            else if(lastPart.back()=='(')
            {
                lastPart.pop_back();
                unbalanced--;
            }
        }
        reverse(lastPart.begin(), lastPart.end());
        return validString.substr(0,i+1)+lastPart;
    }
};
