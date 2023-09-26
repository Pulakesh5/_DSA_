class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        vector<int> lastPos(26,-1);
        int len = s.size();
        for(int i=0; i<len; i++)
            lastPos[s[i]-'a']=i;
        stack<char> stk;
        int top;
        // fill(lastPos.begin(), lastPos.end(), -1);
        vector<bool> used(26,false);
        for(int i=0; i<len; i++)
        {
            if(stk.empty())
            {
                stk.push(s[i]);
                used[s[i]-'a']=true;
                continue;
            }
            if(used[s[i]-'a'])
                continue;
            while(!stk.empty() && lastPos[stk.top() - 'a']>i && stk.top()>s[i])
            {
                used[stk.top()-'a'] = false;
                stk.pop();
            }

            stk.push(s[i]);
            used[s[i]-'a'] = true;
        }
        string ans = "";
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
