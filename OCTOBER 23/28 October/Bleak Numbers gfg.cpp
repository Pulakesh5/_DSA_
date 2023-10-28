class Solution
{
public:
	int is_bleak(int n)
	{
	    // Code here.
	    for(int num = n-1; num>=(n-log2(n)); num--)
	    {
	        if( (num + __builtin_popcount(num)) == n)
	            return 0;
	    }
	    return 1;
	}
};
