class Solution{
	public:
	int nthStair(int n){
	    //  Code here
        if(n<=2)
	        return n;
	    return 1+n/2;
	}
};
