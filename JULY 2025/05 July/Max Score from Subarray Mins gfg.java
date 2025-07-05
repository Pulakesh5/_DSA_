class Solution {
    public int maxSum(int arr[]) {
        // code here
        // Minimum subarray size is 2, first try all adjacent pairs and their sum
        // Now observe that, for an sub-array of size>2
        // let smallest in min1 and second smallest is min2
        // subaray = [min1, ..., min2] 
        // the integers belonging to the gap must be greater than both min1 and min2
        // since they are all greater than max(min1,min2) so our new answer would be min2+the immediate previous integer
        // Now this answer is already checked with the sum of adjacent integer pairs
        
        int ans = Integer.MIN_VALUE;
        int N = arr.length;
        for(int i=1; i<N; i++)
        {
            ans = Math.max(ans, arr[i]+arr[i-1]);
        }
        return ans;
    }
}
