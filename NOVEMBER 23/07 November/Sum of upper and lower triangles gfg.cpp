class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
         int sum1=0;
         int sum2=0;
         int sum=0;
          for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                if( i<j) sum1+=matrix[i][j];
                else if( i>j) sum2+=matrix[i][j];
                 else sum+=matrix[i][j];
              }
          }
        return   {sum1+sum,sum2+sum};
    }
};
