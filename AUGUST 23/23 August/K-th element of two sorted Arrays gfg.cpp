class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(k==1)
            return min(arr1[0], arr2[0]);
        int i1=0, i2=0;
        while(i1<n && i2<m &&(i1+i2)<(k-1))
        {
            if(i1<n && arr1[i1]<=arr2[i2])
                i1++;
            else if(i2<m)
                i2++;
        }
        if(i1<n && i2<m && i1+i2 == (k-1))
            return min(arr1[i1], arr2[i2]);
        if(i2==m)
        {
            while(i1<(n-1) && (i1+i2)<(k-1))
                i1++;
            return arr1[i1];
        }
        else
        {
            while(i2<(m-1) && (i1+i2)<(k-1))
                i2++;
            return arr2[i2];
        }
        
        return -1;
    }
};
