class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    map<char, int> count;
	    int ans = 1, t;
	    int MOD = 1e9+7;
	    int len = s.size();
	    for(int i=0; i<len; i++)
	    {
	        if(count.find(s[i])==count.end())
	        {
	            count[s[i]] = ans;
	            ans = (ans*2)%MOD;
	        }
	        else
	        {
	            t = ans;
	            ans = ((ans*2)%MOD - count[s[i]] + MOD)%MOD;
	            count[s[i]] = t;
	        }
	    }
	    return ans;
	}
};
