// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//First approach
// TC: O(nlogn)
class Solution{
public:
    int *findTwoElement(int *arr, long long n) {
        sort(arr,arr+n);
        int twice=0;
        long long sum=0,sum_n=(n*(n+1)*1ll)/2;
        for(int i=0;i<(n);i++){
            sum+=arr[i];
            if(i>0 && arr[i]==arr[i-1]){
                twice=arr[i];
                sum-=arr[i];
            }
        }
        long long none=(sum_n-sum);
        int* ans;
         ans= new int[2];
        ans[0]=twice;
        ans[1]=none;
        return ans;
    }
};
// Second Approach and better one
// TC: O(n) use modulus and notice one item appears 0 time and one item appears 2 times
class Solution{
public:
    int *findTwoElement(int *arr, long long n) {
        sort(arr,arr+n);
        int twice=0,none=0;
       
       int m=n+1;
        for(int i=0;i<(n);i++){
            int v= arr[i]%m;
            arr[v-1]+=m;
        }
        for(int i=0;i<n;i++){
            if((arr[i]/m)==0)
                none=i+1;
            else if((arr[i]/m)==2)
                twice=i+1;
        }
        int* ans;
         ans= new int[2];
        ans[0]=twice;
        ans[1]=none;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
