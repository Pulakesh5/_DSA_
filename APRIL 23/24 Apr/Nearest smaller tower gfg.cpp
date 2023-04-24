    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int len = arr.size();
        vector<int> pre(len), suf(len);
        stack<int> stk;
        for(int i=0;i<len;i++)
        {
            while(!stk.empty() && arr[stk.top()]>=arr[i])
                stk.pop();
            if(!stk.empty())
                pre[i]=stk.top();
            else
                pre[i]=-1;
            stk.push(i);
        }
        stack<int> stk2;
        for(int i=len-1;i>=0;i--)
        {
            while(!stk2.empty() && arr[stk2.top()]>=arr[i])
                stk2.pop();
            if(!stk2.empty())
                suf[i]=stk2.top();
            else
                suf[i]=-1;
            stk2.push(i);
        }
        vector<int> ans(len);
        
        for(int i=0;i<len;i++)
        {
            if(pre[i]==-1 && suf[i]==-1)
                ans[i]=-1;
            else if(pre[i]==-1)
                ans[i]=suf[i];
            else if(suf[i]==-1)
                ans[i]=pre[i];
            else
            {
                if(abs(i-pre[i])<abs(i-suf[i]))
                    ans[i]=pre[i];
                else if(abs(i-pre[i]) > abs(i-suf[i]))
                    ans[i]=suf[i];
                else if(arr[pre[i]]>arr[suf[i]])
                    ans[i]=suf[i];
                else if(arr[pre[i]]<arr[suf[i]])
                    ans[i]=pre[i];
                else
                    ans[i]=min(pre[i],suf[i]);
            }
        }
        return ans;
    }
