
class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        int n = arr.size();
        vector<int>ans(n);
        int i = 0,j = n-1;
        for(int k = 0;k<n;k++) {
            if(k+1<n && arr[k]!=0 && arr[k+1]!=0 && arr[k] == arr[k+1]) {
                ans[i++] = 2*arr[k];
                arr[k+1] = 0;
            }
            else if(arr[k]!=0) {
                ans[i++] = arr[k];
            }
            else ans[j--] = arr[k];
        }
        return ans;
    }
};
