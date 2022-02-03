// { Driver Code Starts
//Initial template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    string ExcelColumn(int N)
    {
        // Your code goes here
        
        string s="";
        int a=N/26,r=N%26;
        while(N>0){
            r=N%26;
            if(r==0)
                N-=26;
            s=(char)('A'+(r-1+26)%26)+s;
            
            N/=26;
        }
        
        
        
        return s;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.ExcelColumn(n)<<endl;
    }
    return 0;
}
      // } Driver Code Ends
