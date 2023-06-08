class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0, rowCount, n = grid.size(), m = grid[0].size();
        cout<<n<<endl;
        for(int i=0; i<n; i++)
        {
            rowCount =  m - (lower_bound(grid[i].begin(), grid[i].end(), -1, greater<int>()) - grid[i].begin());
            count+= rowCount;
        }
        return count;
    }
};
