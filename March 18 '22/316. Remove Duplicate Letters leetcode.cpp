class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        
        int last_occur[26];
        vector<bool> seen(26,false);
        
        for(int i=0;i<n;i++)
            last_occur[s[i]-'a']=i;
        stack<char> stk;
        
        for(int i=0;i<n;i++){
            if(seen[s[i]-'a']) continue;
            
            while(!stk.empty() && stk.top()>s[i] && i<last_occur[stk.top()-'a'])
            {
                seen[stk.top()-'a']=false;
                stk.pop();
            }
            stk.push(s[i]);
            seen[s[i]-'a']=true;
        }
        
        string ans="";
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
