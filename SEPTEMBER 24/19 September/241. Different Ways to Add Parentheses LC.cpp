class Solution {
private:
    int calculate(int x, int y, char op)
    {
        if(op == '+')
            return x+y;
        else if(op == '-')
            return x-y;
        else if(op == '*')
            return x*y;
        return 0;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;
        bool isNumber = 1;
        for(int i=0; i<expression.size(); i++)
        {
            if(!isdigit(expression[i]))
            {
                isNumber = 0;
                vector<int> leftSubExpression = diffWaysToCompute(expression.substr(0,i));
                vector<int> rightSubExpression = diffWaysToCompute(expression.substr(i+1));

                for(int x:leftSubExpression)
                {
                    for(int y:rightSubExpression)
                    {
                        int value = calculate(x, y, expression[i]);
                        results.push_back(value);
                    }
                }
            }
        }
        if(isNumber)
            results.push_back(stoi(expression));
        return results;
    }
};
