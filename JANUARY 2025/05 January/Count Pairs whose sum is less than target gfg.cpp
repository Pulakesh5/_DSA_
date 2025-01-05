class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(), arr.end());
        int pairCount = 0, N = arr.size();
        int l=0, r=N-1;
        while(l<=r)
        {
            if(arr[l]+arr[r]>=target)
                r--;
            else
            {
                pairCount += (r-l);
                l++;
            }
        }
        return pairCount;
    }
};
