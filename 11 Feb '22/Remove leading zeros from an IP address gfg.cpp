// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
  public:
    string newIPAdd (string s)
    {
        string str=s,ans="";
        str+='.';
        int j=0,n=s.length();
        
        while(j<n){
            while(str[j]=='0') //skipping leading zeroes
                j++;
            if(str[j]=='.')//if all are zeroes, adding one zero
                ans+='0';
            while(str[j]!='.') //copying nonzero digits into ans
            {
                ans+=str[j];j++;
            }
            j++;ans+='.'; //adding '.' at the end of each group of char
        }
        ans.pop_back(); // removing last '.'
    return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends
