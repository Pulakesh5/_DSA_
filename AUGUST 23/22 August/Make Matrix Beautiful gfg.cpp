class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<int> rowSum(n,0), colSum(n,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                rowSum[i]+=matrix[i][j];
                colSum[j]+=matrix[i][j];
            }
        }
        
        int rowSumMax = *max_element(rowSum.begin(), rowSum.end());
        int colSumMax = *max_element(colSum.begin(), colSum.end());
        
        if(rowSumMax>=colSumMax)
        {
            int ans=0;
            for(int i=0; i<n; i++)
                ans+=rowSumMax-colSum[i];
            return ans;
        }
        else
        {
            int ans=0;
            for(int i=0; i<n; i++)
                ans+=colSumMax-rowSum[i];
            return ans;
        }
        return -1;
    } 
};
