class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        // Your code goes here
        int lastOnes=0, currOnes = 0, zeros = 0, maxLength = 0;
        int sum = 0, maxSum = 0, oneCount = 0;
        for(int i=0; i<n; i++)
        {
            if(a[i])
                oneCount++, sum--;
            else
                sum++;
            if(sum>maxSum)
                maxSum = sum;
            if(sum<0)
                sum = 0;
        }
        return maxSum+oneCount;
    }
};
