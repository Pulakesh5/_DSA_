// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int count(int N){
        // code here
       vector<int> dp(N+1,0);
       dp[0]=1;
       
       for(int i=2;i<=N;i+=2){
            for(int j=0;j<i;j+=2)
                dp[i] += dp[j]*dp[i-j-2];
       }
       
       return dp[N];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends
