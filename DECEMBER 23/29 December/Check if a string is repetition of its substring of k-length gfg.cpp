class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    // Your Code Here
	    if(n%k != 0)
	        return 0;
	    map<string,  int> mp;
	    string subString="";
	    subString.push_back(s[0]);
	    for(int i=1; i<n; i++)
	    {
	        if(i%k == 0)
	        {
	            mp[subString]++;
	            subString="";
	        }
	        subString.push_back(s[i]);
	    }
	    mp[subString]++;
	    if(mp.size()>2)
	        return 0;
	   
	   int mxOccurence=0;
	    for(auto it:mp)
	    {
	        mxOccurence = max(mxOccurence, it.second);
	    }
	    return mxOccurence>=(n/k-1);
	}
};
