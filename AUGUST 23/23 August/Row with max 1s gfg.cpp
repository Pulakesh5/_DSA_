int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
// code here
    int maxRow=-1, sum=0, maxSum=0;
    for(int i=0; i<n; i++)
    {
        sum=0;
        for(int j=0; j<m; j++)
            sum+=arr[i][j];
        if(sum>maxSum)
        {
            maxSum = sum;
            maxRow = i;
        }
    }
    return maxRow;
}
