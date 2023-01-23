    string removePair(string s) {
        // code here
        stack<char> stk;
        int len=s.length();
        
        for(int i=0;i<len;i++)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
                continue;
            }
            else if(stk.top()==s[i])
                stk.pop();
            else
                stk.push(s[i]);
        }
        
        string ans="";
        
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        if(ans.size()==0)
            return "-1";
        return ans;
    }
