class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int maxNumber = max(arr[0], arr[1]), secondMax = min(arr[0], arr[1]);
        int N = arr.size();
        for (int i=2; i<N; i++) {
            if(arr[i] > maxNumber) {
                secondMax = maxNumber;
                maxNumber = arr[i];
            } else if(arr[i] > secondMax) {
                secondMax = arr[i];
            }
        }
        return maxNumber+secondMax;
    }
};
