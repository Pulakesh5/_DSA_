class Solution{
public:	
    string check(int num, int len)
    {
        string ans(len,'0');
        int k=len-1;
        while(k>=0 && num)
        {
            ans[k--] = (num%2)+'0';
            num = num/2;
        }
        k = 0;
        int cnt=0;
        while(k<len)
        {
            cnt += (ans[k++]=='1');
            if((k - cnt)>cnt)
                return "-1";
        }
        return ans;
    }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    if(n==1)
	        return {"1"};
	    const int MSB = (1<<(n-1));
	    vector<string> binStrings;
	    string str;
	    for(int i=0; i<(1<<(n-1)); i++)
	    {
	        str = check(MSB+i, n);
	        if(str!="-1")
	            binStrings.push_back(str);
	    }
	    reverse(binStrings.begin(), binStrings.end());
	    return binStrings;
	}
};
