class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char bracket:s)
        {
            if(bracket=='(' || bracket=='{' || bracket=='[')
                stk.push(bracket);
            else
            {
                if(stk.empty())
                    return false;
                if(bracket==')')
                {
                    if(stk.top()=='(') stk.pop();
                    else
                        return false;
                }
                else if(bracket=='}')
                {
                    if(stk.top()=='{') stk.pop();
                    else
                        return false;
                }
                else if(bracket==']')
                {
                    if(stk.top()=='[') stk.pop();
                    else
                        return false;
                }
            }
        }
        return stk.empty();
    }
};
