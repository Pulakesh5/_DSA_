class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        int matched=0;
        int open=0;
        vector<int> brackets;
        stack<int> positions;
        for(char ch:str)
        {
            if(ch=='(' || ch==')')
            {
                if(ch=='(')
                {
                    open++;
                    brackets.push_back(open);
                    positions.push(open);
                }
                else
                {
                    brackets.push_back(positions.top());
                    positions.pop();
                }
            }
        }
        return brackets;
    }
};
