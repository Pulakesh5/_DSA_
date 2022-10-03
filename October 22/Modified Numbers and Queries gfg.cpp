    int sumOfAll(int l, int r){
        // code here
        vector<int> table(r+1,0);
        table[1]=1;
        long long ans=0;
        for(int i=2;i<=(r);i++)
        {
            if(table[i])
            {
                continue;
            }
            for(int j=i;j<=r;j+=i)
            {
                table[j]+=i;
            }
        }
        
        for(int i=l;i<=r;i++)
        {
            ans+=table[i];
        }
        
        return ans;
    }
