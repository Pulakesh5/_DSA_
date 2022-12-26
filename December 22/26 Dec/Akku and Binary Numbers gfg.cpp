    vector<long long> nums;

    void precompute()
    {
        for(int i=0;i<63;i++)
        {
            for(int j=i+1;j<63;j++)
            {
                for(int k=j+1;k<63;k++)
                {
                    // if(k==3)
                    //     cout<<k<<" "<<j<<" "<<i<<endl;
                    nums.push_back(0ll+(1ll<<i)+(1ll<<j)+(1ll<<k));
                }
            }
        }
        //cout<<nums.size()<<endl;
        sort(nums.begin(), nums.end());
        
    }
    
    long long solve(long long l, long long r){
        // Code Here
        int l_itr=lower_bound(nums.begin(), nums.end(),l)-nums.begin();
        int r_itr=lower_bound(nums.begin(), nums.end(),r)-nums.begin();
        
        // for(int i=l_itr;i<=r_itr;i++) cout<<nums[i]<<" ";
        // cout<<endl;
        
        if(nums[r_itr]!=r) r_itr--;
        
        return r_itr-l_itr+1;
        
    }
    
