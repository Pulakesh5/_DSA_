// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++
/*
    Solution Idea: at each index try to make even and odd length pals and store it in a set
*/
class Solution{
  public:
    int palindromeSubStrs(string s) {
        unordered_set<string> st;
        int n=s.length();
        //even pals
        for(int i=0;i<n;i++){
            int left=i,right=i+1;
            string temp="";
            while(left>=0 && right<n && s[left]==s[right])
            {
                temp = s[left] +temp + s[right];
                st.insert(temp);
                left--;right++;
            }
        }
        //odd pals
        for(int i=0;i<n;i++){
            int left=i-1,right=i+1;
            string temp="";
            temp+=s[i];
            st.insert(temp);
            while(left>=0 && right<n && s[left]==s[right])
            {
                temp = s[left] +temp + s[right];
                st.insert(temp);
                left--;right++;
            }
        }
        
        return st.size();
    }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends
