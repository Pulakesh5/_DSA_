// { Driver Code Starts
// CPP program to find maximum sum
// by selecting a element from n arrays
#include<bits/stdc++.h>

using namespace std;

// To calculate maximum sum by
// selecting element from each array
int maximumSum( int n,int m, vector<vector<int>> &a);



// Driver program to test maximumSum
int main() {
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        vector<vector<int>> arr(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            cin>>arr[i][j];
            
        cout << maximumSum(n,m,arr)<<endl;
    
    }
    return 0;

}
// } Driver Code Ends

/*
    Solution Idea: Just use greedy
*/
int maximumSum( int n,int m, vector<vector<int>> &arr) {

    for(auto &it:arr)
        sort(it.begin(), it.end());
    // for(auto a:arr){
    //     for(auto it:a)
    //         cout<<it<<" ";
    //     cout<<'\n';
    // }
    int sum=0,pre=INT_MAX;
    for(int i=n-1;i>=0;i--){
        int j=m-1;
        while(j>=0 && arr[i][j]>=pre)
            j--;
        if(j<0) return 0;
        pre=arr[i][j];
        sum+=pre;
    }
    return sum;
}
