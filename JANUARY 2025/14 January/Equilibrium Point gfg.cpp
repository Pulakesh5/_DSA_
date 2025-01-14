class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int equlibriumPoint = -1;
        int total = accumulate(arr.begin(), arr.end(), 0);
        int prefix = arr[0], n = arr.size();
        total -= arr[0];
        for(int i=1; i<n; i++)
        {
            total -= arr[i];
            if(prefix == total)
            {
                return i;
            }
            prefix += arr[i];
        }
        
        return -1;
    }
};
