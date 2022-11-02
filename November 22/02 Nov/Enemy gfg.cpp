class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            vector<int> arr(k+2), brr(k+2);
            
            arr[0]=0;arr[k+1]=n+1;
            brr[0]=0;brr[k+1]=m+1;
            
            for(int i=0;i<k;i++)
            {
                arr[i+1]=enemy[i][0];
                brr[i+1]=enemy[i][1];
            }
            
            sort(arr.begin(), arr.end());
            sort(brr.begin(), brr.end());
            
            int maxRowDiff=0, maxColDiff=0;
            
            for(int i=1;i<=(k+1);i++)
            {
                maxRowDiff=max(maxRowDiff,arr[i]-arr[i-1]-1);
                maxColDiff=max(maxColDiff,brr[i]-brr[i-1]-1);
                //cout<<maxRowDiff<<" "<<maxColDiff<<endl;
            }
            if(k==0)
            {
                maxRowDiff=n;
                maxColDiff=m;
            }
            
            return maxRowDiff*maxColDiff;
            
        }
};
