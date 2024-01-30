class Solution {
public:
    int calculator(int op1, int op2, char oprtr){
        if(oprtr=='*')
            return op1*op2;
        else if(oprtr=='/')
            return op1/op2;
        else if(oprtr=='+')
            return op1+op2;
        else
            return op1-op2;
    }
    int strToNum(string str)
    {
        int num=0;
        int len=str.size();
        int i = (str[0]=='-'?1:0);
        for(; i<len; i++)
        {
            num = num*10 + (str[i]-'0');
        }
        cout<<str<<" "<<num<<endl;
        if(str[0]=='-')
            return -1*num;
        return num;
        
    }
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==1)
            return strToNum(tokens[0]);
        stack<int> operands;
        operands.push(strToNum(tokens[0]));
        operands.push(strToNum(tokens[1]));
        int len = tokens.size();

        set<string> operators={"+","/","*","-"};
        int op1, op2, result;
        for(int i=2; i<len; i++)
        {
            if(operators.find(tokens[i])!=operators.end())
            {
                op2 = operands.top();
                operands.pop();
                op1 = operands.top();
                operands.pop();
                result = calculator(op1,op2,tokens[i][0]);
                operands.push(result);
                cout<<result<<" : "<<op1<<" "<<op2<<endl;
            }
            else
                operands.push(strToNum(tokens[i]));
        }
        return operands.top();
    }
    
};
