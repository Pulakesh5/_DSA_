class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int R = rowSum.size(), C = colSum.size();
        vector<vector<int>> matrix(R,vector<int>(C));
        int sum, elem;
        for(int i=0; i<R; i++)
        {
            sum = rowSum[i];
            for(int j=0; j<C && sum; j++)
            {
                elem = min(sum, colSum[j]);
                matrix[i][j] = elem;
                sum-=elem;
                colSum[j]-=elem;
            }
        }
        return matrix;
    }
};
