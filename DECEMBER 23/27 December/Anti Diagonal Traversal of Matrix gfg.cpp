class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        int n=matrix.size();
        vector<int> traversal(n*n);
        int k=0;
        for(int c=0; c<n; c++)
        {
            int i=0, j=c;
            while(j>-1)
                traversal[k++] = matrix[i++][j--];
        }
        for(int r=1; r<n; r++)
        {
            int i=r, j=n-1;
            while(i<n)
                traversal[k++] = matrix[i++][j--];
        }
        return traversal;
        
    }
};
