class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        // Your code here
        int N = arr.size();
        int gain = 0, maxGain = 0;
        for(int i=1; i<N; i++)
        {
            if(arr[i]>arr[i-1])
                gain++;
            else
            {
                maxGain = max(maxGain, gain);
                gain = 0;
            }
        }
        maxGain = max(maxGain, gain);
        return maxGain;
    }
};
