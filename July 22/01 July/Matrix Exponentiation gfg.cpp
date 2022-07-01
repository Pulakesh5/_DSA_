class Solution {
public:
    int mod=1000000007;
    void Multiply(long long F[2][2],long long M[2][2]){
        long long a=((F[0][0]*M[0][0])%mod+(F[0][1]*M[1][0])%mod)%mod;
        long long b=((F[0][0]*M[0][1])%mod+(F[0][1]*M[1][1])%mod)%mod;
        long long c=((F[1][0]*M[0][0])%mod+(F[1][1]*M[1][0])%mod)%mod;
        long long d=((F[1][0]*M[0][1])%mod+(F[1][1]*M[1][1])%mod)%mod;
        
        F[0][0]=a;
        F[0][1]=b;
        F[1][0]=c;
        F[1][1]=d;
    }
    
    void Power(long long F[2][2], int n){
        if(n==0 ||n==1) return;
        
        long long M[2][2]={{1ll,1ll},{1ll,0ll}};
        Power(F,n/2);
        Multiply(F,F);
        if((n%2)==1) 
            Multiply(F,M);
    }
    
    int FindNthTerm(long long int n) {
        long long F[2][2]={{1ll,1ll},{1ll,0ll}},M[2][2]={{1ll,1ll},{1ll,0ll}};
        // while(n){
        //     if(n%2==1) F=Multiply(F,M);
        //     M=Multiply(M,M);
        //     n>>=1;
        // }
        Power(F,n);
        return F[0][0];
    }
};
