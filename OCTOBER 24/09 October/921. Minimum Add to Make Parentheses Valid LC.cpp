class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk; 
        int open = 0, close=0;
        for (char ch:s) {
            if(ch == '(')
                open++;
            else {
                if(open)
                    open--;
                else
                    close++;
            }
        }
        return open+close;
    }
};
