
class Solution {
    int missingNum(int arr[]) {
        // code here
        int N = arr.length+1;
        long expectedSum = (1L*N*(N+1))/2, actualSum = 0L;
        for(int num:arr)
            actualSum += num;
        return (int) (expectedSum-actualSum);
    }
}
