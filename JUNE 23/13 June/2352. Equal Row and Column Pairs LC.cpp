class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rowCount, colCount;
        int n=grid.size();
        for(int i=0; i<n; i++)
        {
            rowCount[grid[i]]++;
        }
        vector<int> col(n);
        int c=0;
        for(int i=0; i<n; i++)
        {
            c = 0;
            for(int j=0; j<n; j++)
            {
                col[c++] = grid[j][i];
            }
            colCount[col]++;
        }
        int equalPair = 0;
        int rCount, cCount;
        for(auto row_it: rowCount)
        {
            col = row_it.first;
            if(colCount.find(col)==colCount.end())
                continue;
            rCount = row_it.second;
            cCount = colCount[col];
            equalPair+= (rCount*cCount);
        }
        return equalPair;
    }
};
