class Solution {
  public:
    void prank(long long a[], int n){
        vector<int> ind,ans;
        for(int i = 0; i < n; i++) {
        a[i] = a[i] + (a[a[i]]%n)*n; // this is to store two information 
        }
        for(int i = 0; i < n; i++){
        a[i] = a[i]/n;
        }
    }
};
/*
          i: 0 1 2 3 4 5
     arr[i]: 0 5 1 2 4 3
arr[arr[i]]: 0 3 5 1 4 2 // Ans
let, A=arr[i] , B=arr[arr[i]]
A' = A + B*n 
A = A'% n
B = A / n
*/
