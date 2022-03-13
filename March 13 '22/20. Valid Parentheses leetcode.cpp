class Solution {
public:
    bool isValid(string s) {
        int i=0,n=s.size();
        stack<char> stk;
        stk.push(s[i++]);
        while(i<n){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                stk.push(s[i]);
            else if(!stk.empty()){
                if(s[i]==')' && stk.top()=='(')    // && !stk.empty()
                    stk.pop();
                else if(s[i]=='}' && stk.top()=='{')
                    stk.pop();
                else if(s[i]==']' && stk.top()=='[')
                    stk.pop();
                else
                    return false;
            }
            else
                return false;
            i++;
        }
        return stk.empty();
    }
};
