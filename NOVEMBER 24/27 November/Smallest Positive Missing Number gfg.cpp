class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        // Your code here
        size_t N = arr.size();
        sort(arr.begin(), arr.end());
        int firstPos = lower_bound(arr.begin(), arr.end(), 1) - arr.begin();
        int nextPos = 1;
        
        for(int i=firstPos; i<N; i++)
        {
            if(arr[i]>nextPos)
                return nextPos;
            else
                nextPos = max(nextPos, arr[i]+1);
        }
        return nextPos;
    }
};
