class Solution {
public:

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int N = nums.size();
        vector<int> sum(N+1);
        for(int i=1; i<=N; i++)
            sum[i] = sum[i-1]+nums[i-1];
        vector<int> posLeft(N,0), posRight(N, N-k);
        for(int i=k, prevSum = sum[k]; i<N; i++)
        {
            if(sum[i+1] - sum[i+1-k] > prevSum)
            {
                posLeft[i] = i+1-k;
                prevSum = sum[i+1] - sum[i+1-k];
            }
            else
                posLeft[i] = posLeft[i-1];
        }

        for(int i=N-k-1, prevSum = sum[N]-sum[N-k]; i>=0; i--)
        {
            if(sum[i+k]-sum[i] >= prevSum)
            {
                posRight[i] = i;
                prevSum = sum[i+k] - sum[i];
            }
            else
                posRight[i] = posRight[i+1];
        }
        int maxSum = 0;
        vector<int> index(3);
        for(int i=k; i<=(N-2*k); i++)
        {
            int l = posLeft[i-1], r = posRight[i+k];
            int total = (sum[l+k] - sum[l]) + (sum[i+k]-sum[i]) + (sum[r+k] - sum[r]);
            if(total > maxSum)
            {
                maxSum = total;
                index = {l, i, r};
            }
        }
        return index;
    }
};
