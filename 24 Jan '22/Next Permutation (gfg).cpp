// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
/* solution Idea:   Can use next_permutation function of STL in cpp
                    logic should be find the point (l) where array breaks descending order
                    now find position(r) of the element which is just greater than  a[l]
                    swap (a[l],a[r])
                    sort(l+1,end)
                    
*/
class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        int l=N-2,r=N-1;
        vector<int> a(arr);
        while(l>=0 && a[l]>=a[l+1])
            l--;
        while(a[l]>=a[r])
            r--;
        if(l>=0)
            swap(a[l],a[r]);
        /*for(auto it:a)
             cout<<it<<" ";
         cout<<'\n';*/
        sort(a.begin()+l+1,a.end());
        //next_permutation(a.begin(), a.end());
        return a;
        //8
        //5 1 4 5 3 2 1 1
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends
