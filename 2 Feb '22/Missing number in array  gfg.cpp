// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        sort(array.begin(), array.end());
        int xor_n=0,xor_=0;
        for(int i=0;i<(n-1);i++)
            xor_^=array[i];
            int d=n%4;
        if(d==0)
            xor_n=n;
        else if(d == 1)
            xor_n=1;
        else if(d == 2)
            xor_n=n+1;
        else
            xor_n=0;
        
        return xor_n ^ xor_;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}  // } Driver Code Ends
