class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> stk;
        int N = s.size();
        if(s[0]==')' || s[0]=='}' || s[0]==']')
            return false;
        stk.push(s[0]);
        for(int i=1; i<N; i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                stk.push(s[i]);
            else if( !stk.empty() && s[i] == ')')
            {
                if(!stk.empty() && stk.top() == '(')
                    stk.pop();
                else
                    return false;
            }
            else if( !stk.empty() && s[i] == '}')
            {
                if(stk.top() == '{')
                    stk.pop();
                else
                    return false;
            }
            else if( !stk.empty() && s[i] == ']')
            {
                if(stk.top() == '[')
                    stk.pop();
                else
                    return false;
            }
            else
                return false;
        }
        return stk.empty();
    }
};
