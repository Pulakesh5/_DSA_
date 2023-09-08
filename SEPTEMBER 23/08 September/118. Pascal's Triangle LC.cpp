class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1)
            return {{1}};
        if(numRows==2)
            return {{1}, {1,1}};
        vector<vector<int>> pascalTriangle(numRows);
        pascalTriangle[0] = {1};
        pascalTriangle[1] = {1,1};
        for(int r=3; r<=numRows; r++)
        {
            vector<int> row(r);
            row[0] = 1; row[r-1] = 1;
            for(int i=1;i<(r-1);i++)
                row[i] = pascalTriangle[r-2][i-1]+pascalTriangle[r-2][i];
            pascalTriangle[r-1] = row;
        }
        return pascalTriangle;
    }
};
