// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
/*
    Solution Idea:
                    It's a hard problem but think in terms of numbers where 9 won't appear
                    Try using knowledge of Digital eectronics
                    It is easy enough that you would laugh 
                    hint : Number theory
*/

class Solution{
	public:
    	long long findNth(long long N)
    {
        long long ans=0,t=N,base=1;
        while(t>0){
            ans=base*(t%9)+ans;
            base*=10;
            t/=9;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n , ans;
		cin>>n;
		Solution obj;
		ans = obj.findNth(n);
		cout<<ans<<endl;
	}
}

  // } Driver Code Ends
