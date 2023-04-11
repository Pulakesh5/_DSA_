class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        for(char ch:s)
        {
            if(ch=='*')
                stk.pop();
            else
                stk.push(ch);
        }
        string ans="";
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
