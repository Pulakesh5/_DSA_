class Solution {
public:
    string makeGood(string s) {
        
        stack<char> stk;
        //for(char ch:s) stk.push(ch);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(stk.empty()){
                stk.push(s[i]);
                continue;
            }
            char pre=stk.top();
            if(abs(pre-s[i])==32) stk.pop();
            else
                stk.push(s[i]);
        }

        string ans="";
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
