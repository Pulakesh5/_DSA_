class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        unsigned int pos = 1;
        while(n)
        {
            if(n&1)
                return pos;
            n/=2;
            pos++;
        }
        return 0;
    }
};
