class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.length();
        long long ans=0;
        stack<char> stk;
        int i=0,pre=0,post=0;
        while(i<n){
            if(s[i]=='('){
                i++;
                pre++;
            } 
            else{
                while(i<n && s[i]==')')
                {
                    post++;i++;
                }
                ans+=(1<<(pre-1));
                pre-=post;
                post=0;
            }
        }
        return ans;
    }
};
