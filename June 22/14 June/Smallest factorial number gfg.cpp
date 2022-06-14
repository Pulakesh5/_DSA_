class Solution
{
    public:
    int trailingZeroes(int num){
        int count=0;
        for(int i=5;(num/i)>=1;i*=5)
            count+=(num/i);
        return count;
    }
    int findNum(int n)
    {
        int low=1,high=5*n;
        int mid;
        while(low<high){
            mid = low+(high-low)/2;
            if(trailingZeroes(mid)>=n)
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};
