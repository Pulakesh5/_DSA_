    vector<int> merge(vector<int> &pre, vector<int> &cur){
        int n1=pre.size();
        int n2=cur.size();
        vector<int> ans(n1+n2);
        int i=0,j=0,k=0;
        while(i<n1 && j<n2)
        {
            if(pre[i]<=cur[j])
            {
                ans[k++]=pre[i++];
            }
            else
                ans[k++]=cur[j++];
        }
        
        while(i<n1)
            ans[k++]=pre[i++];
        while(j<n2)
            ans[k++]=cur[j++];
        
        return ans;
    }
	vector<int> DistinctSum(vector<int>nums){
	    // Code here
	    vector<int> preAns; 
	    preAns.push_back(0);
	    
	    int n=nums.size();
	    sort(nums.begin(), nums.end());
	    
	    for(int i=0;i<n;i++)
	    {
	        vector<int> curAns;
	        for(int j=0;j<preAns.size();j++)
	        {
	            if(!binary_search(preAns.begin(), preAns.end(), (nums[i]+preAns[j])))
	            {
	                curAns.push_back(nums[i]+preAns[j]);
	            }
	        }
	        preAns = merge(preAns,curAns);
	    }
	    return preAns;
	}
