class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
        int size = mat.size();
        vector<int> traversal;
        for(int k=0; k<=(2*size-2); k++)
        {
            if(k&1)
            {
                for(int i=k; i>=0; i--)
                {
                    if(i>=size || (k-i)>=size)
                        continue;
                    traversal.push_back(mat[k-i][i]);
                }
            }
            else
            {
                for(int j=k; j>=0; j--)
                {
                    if(j>=size || (k-j)>=size)
                        continue;
                    traversal.push_back(mat[j][k-j]);
                }
            }
        }
        return traversal;
    }
};
