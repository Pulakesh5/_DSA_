//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        if(m==n){
            return -1;
        }
        int ans=1;
        
        int num=m^n;
        while(num>0){
            if(num&1) return ans;
            num=num>>1;
            ans++;
        }
        return ans;
    }
};
