class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& mat) {
        // Code here
        //e->s
        //s->w
        //w->s
        //s->e
        //vector<int> FindExitPoint(int n, int m, vector<vector<int>>& mat) {
        vector<int> ans(2);
        int i = 0, j = 0, dir = 0;  // dir = 0 means starting direction
        
        while((i >= 0 && i < n) && (j >= 0 && j < m)) {
            if(dir == 0) { // 1st direction
                if(mat[i][j] == 1) { // direction change
                    mat[i][j] = 0;
                    i++;
                    dir = 1;
                }
                else // go forward
                    j++;
            }
            else if(dir == 1) { // 2nd direction
                if(mat[i][j] == 1) {
                    mat[i][j] = 0;
                    j--;
                    dir = 2;
                }
                else
                    i++;
            }
            else if(dir == 2) { // 3rd direction
                if(mat[i][j] == 1) {
                    mat[i][j] = 0;
                    i--;
                    dir = 3;
                }
                else
                    j--;
            }
            else { // 4th direction
                if(mat[i][j] == 1) {
                    mat[i][j] = 0;
                    j++;
                    dir = 0;
                }
                else
                    i--;
            }
        }
        // if value goes out of range
        if(i < 0)
            i = 0;
        else if(i >= n)
            i = n-1;
        if(j < 0)
            j = 0;
        else if(j >= m)
            j = m-1;
            
        ans[0] = i;
        ans[1] = j;
        
        return ans;
    }
};
