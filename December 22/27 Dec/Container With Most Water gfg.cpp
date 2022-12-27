long long maxArea(long long A[], int len)
{
    // Your code goes here
    if(len==1) return 0;
    
    int l=0,r=len-1;
    int Container=0,water=0;
    
    while(l<r)
    {
        if(A[l]>=A[r])
        {
            water=(r-l)*A[r];
            r--;
        }
        else
        {
            water=(r-l)*A[l];
            l++;
        }
        Container=max(Container,water);
    }
    return Container;
}
