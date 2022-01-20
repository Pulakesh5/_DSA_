// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		int binary_to_decimal(string &str)
		{
		   int n=str.length(),i;
		   i=n-1;
		   int base=1,ans=0;
		   while(i>=0){
		      ans+=(base*(str[i]-'0'));
		      base*=2;
		      i--;
		   }
		   return ans;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string str;
    	cin >> str;
    	Solution ob;
    	int  ans = ob.binary_to_decimal(str);
    	cout << ans <<"\n";
    }
	return 0;
}  // } Driver Code Ends
