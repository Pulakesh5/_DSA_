class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        // code here
        long long TotalSum = accumulate(A.begin(), A.end(), 0);
        long long prefixSum=0;
        int positions=0;
        for(int i=0;i<N;i++)
        {
            if((2*prefixSum)==(TotalSum-A[i]))
                return i+1;
            prefixSum+=A[i];
        }
        return -1;
    }
};
