class Solution{
public: 
    bool isPrime(int N)
    {
        if(N==1)
            return false;
        if(N==2 || N==3)
            return true;
        for(int d=2; d<=sqrt(N); d++)
            if(N%d==0)
                return false;
        return true;
    }
    long long int largestPrimeFactor(int N){
        // code here
        if(isPrime(N))
            return N;
        int ans = -1;
        for(int d = 1; d<=sqrt(N); d++)
        {
            if(N%d)
                continue;
            // cout<<d<<" "<<N/d<<endl;
            if(isPrime(d))
            {
                ans = max(ans,d);
                // cout<<d<<" is prime"<<endl;
            }
            if(isPrime(N/d))
            {
                ans = max(ans,N/d);
                // cout<<N/d<<" is prime"<<endl;
            }
                
        }
        return ans;
    }
};
