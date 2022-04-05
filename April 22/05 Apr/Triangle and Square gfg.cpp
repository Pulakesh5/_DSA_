class Solution{
    public:
    int countSquare(int B)
    {
        if(B<4) return 0;
        int l=(B-2)/2;
	    return l*(l+1)/2;
    }
};
