class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        // code here
        int n=matrix.size(), m=matrix[0].size();
        vector<int> snakePattern;
        for(int i=0; i<n; i++)
        {
            if(i%2 == 0)
            {
                for(int j=0; j<m; j++)
                    snakePattern.push_back(matrix[i][j]);
            }
            else
            {
                for(int j=m-1; j>-1; j--)
                    snakePattern.push_back(matrix[i][j]);
            }
        }
        return snakePattern;
    }
};
