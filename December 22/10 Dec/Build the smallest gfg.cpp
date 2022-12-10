string buildLowestNumber(string num, int k)
{
    //code here.
    stack<char> stk;
    int n=num.size();
    
    for(int i=0;i<n;i++)
    {
        while(!stk.empty() && stk.top()>num[i] && k)
        {
            stk.pop();
            k--;
        }
        stk.push(num[i]);
    }
    string ans="";
    while(!stk.empty() && k--) stk.pop();
    
    while(!stk.empty())
    {
        ans+=stk.top();
        stk.pop();
    }
    
    while(ans.back()=='0') ans.pop_back();
    
    reverse(ans.begin(), ans.end());
    
    return ans==""?"0":ans;
}
