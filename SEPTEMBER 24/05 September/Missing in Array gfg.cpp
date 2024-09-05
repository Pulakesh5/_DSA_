class Solution {
  public:

    // Note that the size of the array is n-1
    int missingNumber(int n, vector<int>& arr) {
        long long total = (n*(n+1))/2;
        for(int num:arr)
            total -= num;
        return total;
    }
};
