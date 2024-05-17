class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int l=0, r=1, diff;
        while(l<n && r<n)
        {
            diff = (arr[r]-arr[l]);
            if(diff==x && l!=r)
                return 1;
            else if(diff<x)
                r++;
            else
                l++;
        }
        return -1;
    }
};
