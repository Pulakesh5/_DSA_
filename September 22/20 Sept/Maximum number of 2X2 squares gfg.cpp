class Solution
{
    public:
    long long int numberOfSquares(long long int base)
    {
        //code here
        if(base<=1) return 0;
        long long int Squares=base/2;
        Squares-=1;
        Squares=(Squares*(Squares+1))/2;
        // for(;base>1;base-=2)
        // {
        //     Squares+=((base-2)/2);
        // }
        return Squares;
    }
};
