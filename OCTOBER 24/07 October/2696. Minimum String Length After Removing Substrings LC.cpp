class Solution {
public:
    int minLength(string s) {
        stack<char> stk;
        int len = s.size();
        if(len == 0)    
            return 0;
        stk.push(s[0]);
        for(int i=1; i<len; i++) {
            if(stk.empty()) {
                stk.push(s[i]);
            } else if(s[i]=='B' && stk.top()=='A') {
                stk.pop();
            } else if(s[i]=='D' && stk.top()=='C') {
                stk.pop();
            } else {
                stk.push(s[i]);
            }
        }
        return stk.size();
    }
};
