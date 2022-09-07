    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here        
        vector<long long> ans(n,0ll);
        long long mul=1;
        int zero=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0) 
                mul*=nums[i];
            else
                zero++;
            
        }
        if(zero>1) return ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                ans[i]=mul;
            else if(!zero)
                ans[i]=(mul/nums[i]);
        }
        
        return ans;
    }
