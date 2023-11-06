class Solution{
public:

    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        vector<int> ans;
        for(int i = 0; i < q; i++) {
            int sum = 0;
            if(queries[i][0] == 1) {
                for(int j = -1; j <= 1; ++j) {
                    for(int k = -1; k <= 1; ++k) {
                        int r = queries[i][1] + j, c = queries[i][2] + k;
                        if(r>=0 and c>=0 and r<n and c<m and (abs(j) == 1 or abs(k) == 1))
                            sum += mat[r][c];
                    }
                }
            }
            else{
                for(int j = -2; j <= 2; ++j) {
                    for(int k = -2; k <= 2; ++k) {
                        int r = queries[i][1] + j, c = queries[i][2] + k;
                        if(r>=0 and c>=0 and r<n and c<m and (abs(j) == 2 or abs(k) == 2))
                            sum += mat[r][c];
                    }
                }
            }
            ans.push_back(sum);
        }

        return ans;
    }
};
