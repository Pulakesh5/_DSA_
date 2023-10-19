class Solution {
public:
    string removeBackspace(string s)
    {
        stack<char> stk;
        for(char ch:s)
        {
            if(ch=='#')
            {
                if(stk.empty())
                    continue;
                else
                    stk.pop();
            }
            else
                stk.push(ch);
        }
        string ans = "";
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        string _s = removeBackspace(s);
        string _t = removeBackspace(t);
        return _s == _t;
    }
};
