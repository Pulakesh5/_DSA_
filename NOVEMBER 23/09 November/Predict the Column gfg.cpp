class Solution{
    public:
    /*Function to count zeros in each column
    * N : Number of rows and columns in array
    M is the matrix that is globally declared
    */
    int columnWithMaxZeros(vector<vector<int>>arr,int N){
        
        // Your code here
        int maxZero=0, zeroCount=0, column=-1;
        for(int i=0; i<N; i++)
        {
            zeroCount=0;
            for(int j=0; j<N; j++)
            {
                zeroCount+=(arr[j][i]==0);
            }
            if(zeroCount > 0 && maxZero<zeroCount)
            {
                column = i;
                maxZero = zeroCount;
            }
        }
        return column;
        
    }
};
