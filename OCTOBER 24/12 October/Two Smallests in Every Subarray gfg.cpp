class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        int len = arr.size();
        if(len<2)
            return -1;
        int windowSum = arr[0]+arr[1], maxSum = windowSum;
        for(int i=2; i<len; i++) {
            windowSum+=arr[i];
            windowSum-=arr[i-2];
            if(windowSum>maxSum)
                maxSum = windowSum;
        }
        return maxSum;
    }
};
