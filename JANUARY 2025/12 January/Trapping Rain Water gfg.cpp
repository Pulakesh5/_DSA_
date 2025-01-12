class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int N = arr.size();
        
        vector<int> suffixMax(N+1);
        suffixMax[N-1] = arr[N-1];
        for(int i=N-2; i>-1; i--)
            suffixMax[i] = max(suffixMax[i+1], arr[i]);
            
        int trappedWater = 0, prevHeight = arr[0];
        
        for(int i=1; i<N; i++)
        {
            trappedWater += max(0, min(prevHeight, suffixMax[i+1])-arr[i]);
            prevHeight = max(prevHeight, arr[i]);
        }
        
        return trappedWater;
    }
};
