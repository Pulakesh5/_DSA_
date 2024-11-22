class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int ROW = matrix.size(), COL = matrix[0].size();
        int maxEqualRows = 1;
        for(int i=0; i<ROW; i++)
        {
            int count = 1;
            for(int j=i+1; j<ROW; j++)
            {
                if(matrix[i] == matrix[j])
                    count++;
                else
                {
                    int same = 0;
                    for(int k=0; k<COL; k++)
                    {
                        if(matrix[i][k] == matrix[j][k])
                        {
                            same = 1;
                            break;
                        }
                    }
                    count += (1-same);
                }
            }
            if(count>maxEqualRows)
                maxEqualRows = count;
        }
        return maxEqualRows;
    }
};
