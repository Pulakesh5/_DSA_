class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int N = arr.size();
        if(N<=2)
            return {};
        
        vector<int> preMin(N), sufMax(N);
        preMin[0] = arr[0];
        for(int i=1; i<N; i++)
            preMin[i] = min(preMin[i-1], arr[i]);
        sufMax[N-1] = arr[N-1];
        for(int i=N-2; i>=0; i--)
            sufMax[i] = max(sufMax[i+1], arr[i]); 
        
        for(int i=1; i<(N-1); i++)
        {
            if(preMin[i-1]<arr[i] && arr[i]<sufMax[i+1])
                return {preMin[i-1], arr[i], sufMax[i+1]};
        }
        return {};
    }
};
