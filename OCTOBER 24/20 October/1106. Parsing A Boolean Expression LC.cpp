class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        for(char ch:expression) {
            if(ch == ',' || ch == '(')
                continue;
            if(ch == 't' || ch == 'f' || ch == '!' || ch == '&' || ch == '|')
                stk.push(ch);
            else if(ch == ')') {
                bool hasTrue = false, hasFalse = false;
                while(stk.top() != '!' && stk.top() != '&' && stk.top() != '|') {
                    if(stk.top() == 't')
                        hasTrue = true;
                    else if(stk.top() == 'f')
                        hasFalse = true;
                    stk.pop();
                }

                char op = stk.top();
                stk.pop();
                if(op == '!')
                    stk.push(hasTrue ? 'f' : 't');
                else if(op == '&')
                    stk.push(hasFalse ? 'f' : 't');
                else 
                    stk.push(hasTrue ? 't' : 'f');
            }
        }
        return stk.top() == 't';
    }
};
