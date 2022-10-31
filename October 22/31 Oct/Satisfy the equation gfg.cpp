    vector<int> satisfyEqn(int A[], int N) {
        // code here
        map<int,pair<int,int>> mp;
        vector<int> ans,v;
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                int sum=A[i]+A[j];
                if(mp.find(sum)!=mp.end())
                {
                    auto index=mp[sum];
                    if(index.first!=i && index.first!=j && index.second!=i && index.second!=j)
                    {
                        v={index.first,index.second,i,j};
                        if(ans.size()==0 || ans>v)
                            ans=v;
                    }
                }
                else
                    mp[sum]={i,j};
            }
        }
        if(ans.size()==0) ans={-1,-1,-1,-1};
        return ans;
    }
