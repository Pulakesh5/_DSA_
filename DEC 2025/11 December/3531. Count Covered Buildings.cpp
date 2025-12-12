class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        vector<int> row_left(n+5,n+1), row_right(n+5,0), col_up(n+5, 0), col_down(n+5,n+1);

        for(int i=1; i<=n; i++)
        {
            // set row_lefts to be n+1
            row_left[i] = n+1;
            // set row_rights to be 0
            row_right[i] = 0;
            // set col_ups to be 0
            col_up[i] = 0;
            // set col_down to be n+1
            col_down[i] = n+1;
        }
        int row, col;
        for(vector<int> &building:buildings) { // processing each building for finding limits
            row = building[1];
            col = building[0];
            row_left[row] = min(row_left[row], col);
            row_right[row] = max(row_right[row], col);

            col_up[col] = max(col_up[col], row);
            col_down[col] = min(col_down[col], row);
        }


        int covered_building = 0;
        for(vector<int> &building:buildings) { // find answer
            row = building[1];
            col = building[0];
            if(row_left[row]< col && row_right[row]>col && col_up[col]>row && col_down[col]<row) // building exists in left, right, up and down direction
                covered_building++;
        }
        return covered_building;
    }
};
