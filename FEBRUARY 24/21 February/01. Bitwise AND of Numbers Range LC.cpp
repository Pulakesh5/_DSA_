class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        long long p;
        long long bitWiseAND=0;
        for(int i=30; i>-1; i--)
        {
            p = 1<<i;
            if((left&p)!=(right&p))
                return bitWiseAND;
            else if(left&p)
                bitWiseAND+=p;
        }
        return bitWiseAND;
    }
};

/*


*/
