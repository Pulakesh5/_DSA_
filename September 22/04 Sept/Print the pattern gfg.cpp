    vector<string> pattern(int n){
        // code here
        vector<string> ans(n,"");
        int num=1;
        for(int i=0;i<n;i++)
        {
            for(int d=0;d<i;d++)
                ans[i]+="--";
            for(int d=i;d<n;d++)
                ans[i]+=(to_string(num++)+"*");
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=(n-1-i);j++)
            {
                ans[i]+=to_string(num++);
                if(j!=(n-1-i))
                    ans[i]+="*";
            }
        }
        
        return  ans;
    }
