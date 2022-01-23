// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Simple counting sort logic
class Solution
{
  public:
    string arrangeString(string str)
    {
        int n=str.length(),sum=0;
        unordered_map<char,int> count;
        for(int i=0;i<n;i++){
            if(str[i]>='A' && str[i]<='Z')
            {
                count[str[i]]++;
            }
            else
                sum+=(str[i]-'0');
        }
        for(int i=0;i<26;i++){
            
            if(count['A'+i]>0)
            {
                for(int j=0;j<count['A'+i];j++)
                    cout<<(char)('A'+i);
            }
        }
        if(sum>0)
            cout<<sum;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s) << endl;
    }
return 0;
}

  // } Driver Code Ends
