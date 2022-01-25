// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

// Use Binary Search
class Solution {
  public:
  
    int leastWeightCapacity(int arr[], int N, int D) {
        int sum=0,l=0,r=0;
        sum = accumulate(arr, arr+N, 0);
        l= *max_element(arr, arr+N);
        r=sum;
        int cap = 0,ans =0;
        while(l<=r){
            cap = l+(r-l)/2;
         if(check(arr, N, D, cap)){
            ans=cap;
            r=cap-1;
         }
         else
            l=cap+1;
        }
         return ans;
    }
    
    bool check(int arr[], int N,  int D, int capacity){
        int sum=0,count=1;
        for(int i=0;i<N;i++){

            if(sum+arr[i]<=capacity){
                sum+=arr[i];
            }
            else{
                count++;
                sum=arr[i];
            }
            
        }
        return count<=D;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}  // } Driver Code Ends
