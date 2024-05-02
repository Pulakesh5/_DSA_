class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> stk;
        
        for(char ch:x)
        {
            if(ch=='(' || ch=='{' || ch=='[')
                stk.push(ch);
            else if(ch==')')
            {
                if(stk.empty())
                    return false;
                else if(stk.top()=='(')
                    stk.pop();
                else
                    return false;
            }
            else if(ch=='}')
            {
                if(stk.empty())
                    return false;
                else if(stk.top()=='{')
                    stk.pop();
                else
                    return false;
            }
            else if(ch==']')
            {
                if(stk.empty())
                    return false;
                else if(stk.top()=='[')
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
