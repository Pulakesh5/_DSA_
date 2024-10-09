class Solution
{
    public:
    int maxSubsetXOR(int arr[], int N)
    {
        //Your code here
        int maxXor=0, maxElement = 0;
        if(N==0)
            return 0;
        while (true) {
            maxElement = *max_element(arr, arr+N);
            if(maxElement == 0)
                return maxXor;
            maxXor = max(maxXor, maxXor^maxElement);
            for(int i=0; i<N; i++)
                arr[i] = min(arr[i], arr[i]^maxElement);
        }
        return maxXor;
    }
};
