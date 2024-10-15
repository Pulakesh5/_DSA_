class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int target) {
        // Your code here
        map<long long, int> prevCount;
        prevCount[0] = 1;
        long long sum = 0, subarrayCount = 0;
        for(int num:arr) {
            sum += num;
            subarrayCount += prevCount[sum-target];
            prevCount[sum]++;
        }
        return subarrayCount;
    }
};
