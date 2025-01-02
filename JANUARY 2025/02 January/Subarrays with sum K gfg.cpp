class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        map<int, int> remainderCount;
        remainderCount[0] = 1;
        int sum = 0, N = arr.size();
        int subarrayCount = 0, d, rem;
        for(int i=0; i<N; i++)
        {
            sum += arr[i];
            subarrayCount += remainderCount[sum-k];
            remainderCount[sum]++;
        }
        return subarrayCount;
    }
};
