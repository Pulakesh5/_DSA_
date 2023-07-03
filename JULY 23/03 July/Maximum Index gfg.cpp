class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        int count = 0;
        // check if the arr is decreasing, then answer is 0
        for(int i=0; i<(n-1); i++)
        {
            if(arr[i]>arr[i+1])
                count++;
        }
        if(count == (n-1))
            return 0;
        int maxIndexDiff = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=n-1; j>i; j--)
            {
                if(arr[i]>arr[j])
                    continue;
                if((j-i)<maxIndexDiff)
                    break;
                maxIndexDiff = max(maxIndexDiff, (j-i));
                break;
            }
        }
        return maxIndexDiff;
    }

};
