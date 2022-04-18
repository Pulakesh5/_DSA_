class Solution {
  public:
  long long int mod=1e9+7;
  long long binPow(long long int n, long long  int p){
      if(p==0) return 1ll;
      long long ans,res=binPow(n,p/2); 
      ans=(res * res) %mod;
      if(p%2==1){
          ans=(ans * n)%mod;
      }
      return ans;
  }
    long long karyTree(int k, int m) {
        return binPow(k,m);
    }
};
