class Solution{
	public:
	vector<int> FactDigit(int N)
	{
	    // Code here
	    vector<int> fact(10,1);
	    for(int i=1;i<10;i++)
	    {
	        fact[i]=fact[i-1]*i;
	    }
	    int f=9;
	    string num="";
	    
	    while(N>0 && f>0){
	        
	        while(N>=fact[f]){
	            N-=fact[f];
	           num+=(f+'0');
	        }
	        f--;
	    }
	    
	    vector<int> ans;
	    for(int i=num.size()-1;i>=0;i--)
	        ans.push_back(num[i]-'0');
	    return ans;
	}
};
