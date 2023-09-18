class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here    
        while(n)
        {
            if(n&1)
            {
                if(n==1)
                    return true;
                else
                    return false;
            }
            n>>=1;
        }
        return false;
        
    }
};
