// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

// This is a very good question can revise lucas theorem an dfermat's littile theorem for nCr of large numbers 
class Solution {
private:
       long long BinExpo(long long a,long long pow,long long mod){
        long long ans=1;
        
        while(pow>0){
            if(pow&1) ans = (ans*a)%mod;
            a=(a*a)%mod;
            pow=pow>>1;
        }
        return ans;
        
    }
    long long ModInv(long long num,long long mod){
        //(b^-1)%mod = b^(mod-2)%mod, comes from Fermat's little theorem
        return BinExpo(num,mod-2,mod);
    }
    
    long long fermat(long long n, long long r,long long mod){
        if(n<r)
            return 0;
        if(r==0 || r==n)
            return 1;
        if(r==n-1 || r==1)
            return n;
        long long fact[n+2];
        
        fact[0]=1;
        int i=0;
        for(i=1;i<=n;i++)
            fact[i] = (fact[i-1]*i % mod);
        
        long long a = fact[n];
        long long b = ModInv(fact[r],mod);
        long long c = ModInv(fact[n-r],mod);
        return ((a * b)%mod * c)%mod;
    }
    long long lucas(long long  n,long long r, long long mod){
        if(r==0) 
            return 1;
        long long  _n=n%mod, _r=r%mod;
        return (lucas(n/mod,r/mod,mod) * fermat(_n,_r,mod)) %mod;
    }
    long long __nCr(long long n, long long r,long long mod){
        if(r>n || n<0 || r<0) return 0;
        return lucas(n,r,mod);
    } 
public:
int nCr(long long n, long long r) {
    long long mod= 1000003;

    return lucas(n,r,mod);
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long n, r;
		cin >> n >> r;
		Solution obj;
		int ans = obj.nCr(n, r);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
