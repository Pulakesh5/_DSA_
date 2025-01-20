class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>> pos(m*n+1);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                pos[mat[i][j]] = {i, j};
            }
        }
        vector<int> notPaintedRow(m, n), notPaintedCol(n, m);
        for(int k=0; k<(m*n); k++)
        {
            auto [x, y] = pos[arr[k]];
            notPaintedRow[x]--;
            notPaintedCol[y]--;
            if(notPaintedRow[x]==0 || notPaintedCol[y]==0)
                return k;
        }
        return -1;
    }
};
