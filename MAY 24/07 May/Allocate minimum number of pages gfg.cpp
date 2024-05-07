class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool check(int A[], int N, int M, int pages)
    {
        int total=0, student=1;
        for(int i=0; i<N; i++)
        {
            if(A[i]>pages)
                return false;
            if(total+A[i]<=pages)
                total+=A[i];
            else
            {
                student++;
                total = A[i];
            }
            if(student>M)
                return false;
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M)
            return -1;
        if(N==M)
            return *max_element(A, A+N);
        // sort(A, A+N);
        int low=0, high=0;
        for(int i=0; i<N; i++)
        {
            low = max(low, A[i]);
            high+=A[i];
        }
        int mid, ans=0;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(check(A, N, M, mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};
