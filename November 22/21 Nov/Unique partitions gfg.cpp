class Solution{
	public:
	vector<vector<int>> vv;
	void dfs(int n, int curr, vector<int> &vec)
	{
	    if(n==0){
	        vv.push_back(vec);
	        return;
	    }
	    for(int i=curr;i>0 ;i--)
	    {
	        if(n-i>=0)
	        {
	            vec.push_back(i);
	            dfs(n-i,i,vec);
	            vec.pop_back();
	        }
	    }
	    
	}
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<int> vec;
        int curr=n;
        dfs(n,curr,vec);
        return vv;
    }
};
