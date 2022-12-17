class Solution{   
public:
    int waysToBreakNumber(int N){
        // code here 
        long long mod=1e9+7;
        long long n=N,r=2;
        
        return (((n+r)*(n+r-1))%mod)/2;
    }
};
