class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        int length=0;
        stack<int> stk;
        
        for(int i=0;i<n;i++){
            if(s[i]=='(') 
                stk.push(i);
            else{
                if(!stk.empty()){
                    if(s[stk.top()]=='(') 
                        stk.pop();
                    else    
                        stk.push(i);
                }
                else
                    stk.push(i);
            }
        }
        if(stk.empty())
            length=n;
        else{
            int a=n,b=0;
            while(!stk.empty()){
                b=stk.top();
                stk.pop();
                length=max(length,a-b-1);
                a=b;
            }
            length=max(length,a);
        }
        return length;
    }
};
