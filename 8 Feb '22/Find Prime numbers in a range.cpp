// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
// This solution uses the  concept of segmented sieve
// primarily sieve to get primes in range [2,sqrt(high)]
// using these primes sieve in the range of [low,high] 
class Solution {
  public:
  void set_primes(vector<int> &primes, int high){
      int size=sqrt(high)+1;
      bool mark[size];
      memset(mark,true,sizeof(mark));
      mark[0]=false;mark[1]=false;
      for(int i=2;i*i<=high;i++){
          if(mark[i]){
              for(int j=i*i;j<=sqrt(high);j+=i)
                mark[j]=false;
          }
      }
      for(int i=2;i*i<=high;i++)
        if(mark[i])
            primes.push_back(i);
  }
    vector<int> primeRange(int M, int N) {
        
        vector<int> primes,ans;
        set_primes(primes,N);
        
        bool mark[N-M+1];
        memset(mark,true,sizeof(mark));
        if(M==1) mark[0]=false;
        for(auto i:primes){
            //cout<<i<<" ";
            int l=(M)/i;
            if(l<=1)
                l=2;
            else if(M%i)
                l+=1;
            l*=i;
            //cout<<"l "<<l<<" ";
            for(int j=l;j<=N;j+=i){
                mark[j-M]=false;
            }
        }
        //cout<<'\n';
        for(int i=M;i<=(N);i++)
            if(mark[i-M])
                ans.push_back(i);
        return ans;
    }
};
// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends
