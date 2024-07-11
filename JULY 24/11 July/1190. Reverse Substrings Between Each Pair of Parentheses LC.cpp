class Solution {
public:
    string reverseParentheses(string s) {
        int len = s.size();
        stack<string> stk;
        string str = "";
        for(int i=0; i<len; i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                str.push_back(s[i]);
            }
            else if(s[i]=='(')
            {
                stk.push(str);
                str = "";
            } 
            else if(s[i]==')')
            {
                if(str.size())
                {
                    // stk.push(str);
                    reverse(str.begin(), str.end());
                    if(!stk.empty())
                    {
                        string top = stk.top();
                        stk.pop();
                        str = top + str;
                    }
                    else
                        stk.push(str);
                }
                else
                {
                    str = stk.top();
                    stk.pop();
                }
            }
        }
        while(!stk.empty())
        {
            str = stk.top() + str;
            stk.pop();
        }
        return str;
    }
};
