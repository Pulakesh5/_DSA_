class Solution{
public:	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int l=0, r=S.size()-1;
	    while(l<r)
	    {
	        if(S[l] != S[r])
	            return 0;
	        l++;
	        r--;
	    }
	    return 1;
	}

};
