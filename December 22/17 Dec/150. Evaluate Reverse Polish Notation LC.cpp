class Solution {
public:
    bool isOperator(string st)
    {
        return st=="+" || st=="-" || st=="*" || st=="/";
    }
    int op(string token)
    {
        return (token=="+"?0:(token=="-"?1:(token=="*"?2:3)));
    }
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;
        long long num1,num2;
        for(string token:tokens)
        {
            if(isOperator(token))
            {
                num2=stk.top();
                stk.pop();
                num1=stk.top();
                stk.pop();
                if(op(token)==0)
                    stk.push(num1+num2);
                else if(op(token)==1)
                    stk.push(num1-num2);
                else if(op(token)==2)
                    stk.push(num1*num2);
                else if(op(token)==3)
                    stk.push(num1/num2);
            }
            else
                stk.push(stoi(token));
        }
        return stk.top();
    }
};
