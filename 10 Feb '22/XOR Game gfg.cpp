// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int xorCal(int k){
        //cout<<3&(4);
        if(k==1) return 2;
        if((k&1)==0) return -1; //even k doesn't have any solution becuase LSB of consecutive numbers differ by 1
        if((k&(k+1)) == 0) return (k/2); // (n+1) should be a power of 2,n^(n+1)=n+n+1=2n+1=k => n=(k-1)/2
        
        return -1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        
        Solution ob;
        cout<<ob.xorCal(k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
