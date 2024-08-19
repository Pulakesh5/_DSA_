class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int N = arr.size();
        vector<bool> present(1e6+1, false);
        int mx = INT_MIN;
        for(int num:arr)
        {
            present[num] = true;
            mx = max(mx, num);
        }
        for(int i=1; i<=1e6; i++)
        {
            if(present[i])
                --k;
            if(k==0)
                return i;
        }
        return -1;
    }
};
