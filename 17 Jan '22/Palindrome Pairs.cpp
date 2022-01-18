


// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
/*
    Solution Idea:  You need knowledge of a new data structure Trie
                    though this particular solution is not based on that, 
                    Read about Trie and try to solve it in that method
*/
class Solution{   
  public:
    // Function to check if a palindrome pair exists
    bool palindromepair(int N, string arr[]) {
        if(N<2) return 0;
        unordered_map<char, vector<int>> mp;
        for(int i=0;i<N;i++)
            mp[arr[i].back()].push_back(i);
        
        for(int i=0;i<N;i++){
            
            for(auto j:mp[arr[i][0]]){
                if(i==j)
                    continue;
                if(ispal(arr[i]+arr[j]))
                    return true;
            }
        }
        
        return 0;
    }
    bool ispal(string str){
        int i=0,j=str.length()-1;
        while(i<j){
            if(str[i++]!=str[j--])
                return 0;
        }
        
        return true;
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
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
