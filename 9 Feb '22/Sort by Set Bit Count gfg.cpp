// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    static bool comp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
        if(a.first==b.first){
            return a.second.first < b.second.first;
        }
        return a.first > b.first;
    }
    void sortBySetBitCount(int arr[], int n)
    {
       vector<pair<int,pair<int,int>>> a;
       for(int i=0;i<n;i++){
           a.push_back({__builtin_popcount(arr[i]),{i,arr[i]}});
       }
       sort(a.begin(), a.end(), comp);
       for(int i=0;i<n;i++){
           arr[i]=a[i].second.second;
       }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
