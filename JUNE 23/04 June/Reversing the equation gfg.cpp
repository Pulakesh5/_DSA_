string reverseEqn (string s)
{
    //code here.
    stack<string> operands;
    stack<char> operators;
    int len = s.size();
    string operand="";
    for(int i=0; i<len; i++)
    {
        if(s[i]>='0' && s[i]<='9')
            operand.push_back(s[i]);
        else
        {
            operands.push(operand);
            operand="";
            operators.push(s[i]);
        }
    }

    string reverseEquation = operand;

    while(!operators.empty())
    {
        reverseEquation.push_back(operators.top());
        operators.pop();
        reverseEquation+=operands.top();
        operands.pop();
    }
    return reverseEquation;
}
