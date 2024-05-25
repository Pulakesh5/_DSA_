class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        long long maxWindowSum = 0, windowSum = 0;
        for(int i=0; i<n;)
        {
            int j=i;
            windowSum = 0;
            while(j<n && arr[j]<=k)
            {
                windowSum += arr[j];
                j++;
            }
            
            maxWindowSum = max(maxWindowSum, windowSum);
            
            if(i==j)
                i++;
            else
                i = j;
        }
        return maxWindowSum;
    }
};
