class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        size_t ROW = matrix.size(), COL = matrix[0].size();
        int negativeCount = 0;
        int minElement = INT_MAX;
        long long matrixSum = 0;
        for(int i=0; i<ROW; i++)
        {
            for(int j=0; j<COL; j++)
            {
                if(matrix[i][j]<0)
                {
                    negativeCount ++;
                    minElement = min(minElement, -1*matrix[i][j]);
                }
                else
                    minElement = min(minElement, matrix[i][j]);
                matrixSum += abs(matrix[i][j]);
            }
            // cout<<i<<" "<<minElement<<endl;
        }
        if(negativeCount%2 == 0)
            return matrixSum;
        return matrixSum - 2*minElement;
    }
};
