class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        unordered_map<string, int> smooth_operator;
        smooth_operator["+"] = 1;
        smooth_operator["-"] = 2;
        smooth_operator["*"] = 3;
        smooth_operator["/"] = 4;
        stack<string> operators;
        stack<int> operands;
        for(string str:arr)
        {
            if(smooth_operator.count(str))
            {
                int operand1 = operands.top();
                operands.pop();
                int operand2 = operands.top();
                operands.pop();
                
                // cout<<str<<" "<<operand1<<", "<<operand2<<endl;
                
                switch(smooth_operator[str])
                {
                    case 1:
                            operands.push(operand1+operand2);
                            break;
                    case 2:
                            operands.push(operand2-operand1);
                            break;
                    case 3:
                            operands.push(operand1*operand2);
                            break;
                    case 4:
                            operands.push(operand2/operand1);
                            break;
                }
            }
            else
                operands.push(stoi(str));
        }
        return operands.top();
    }
};
