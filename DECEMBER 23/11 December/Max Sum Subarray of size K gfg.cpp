class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &A, int N){
        // code here 
        long windowSum = 0, maxWindowSum=0;
        for(int i=0; i<N; i++)
        {
            if(i<K)
            {
                windowSum+=A[i];
                continue;
            }
            maxWindowSum = max(maxWindowSum, windowSum);
            windowSum -= A[i-K];
            windowSum += A[i];
        }
        maxWindowSum = max(maxWindowSum, windowSum);
        return maxWindowSum;
    }
};
