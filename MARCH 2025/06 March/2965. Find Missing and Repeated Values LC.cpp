class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int n_sq = n*n;
        long long exp_sum = 1ll*n_sq*(n_sq+1)/2;
        long long exp_square_sum = 1ll*n_sq*(n_sq+1)*(2*n_sq+1)/6;

        long long sum = 0, square_sum = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                sum += grid[i][j];
                square_sum += (1ll*grid[i][j]*grid[i][j]);
            }
        }
        long long diff_sum = sum - exp_sum; // a-b
        long long diff_square_sum = square_sum - exp_square_sum; // a^2 - b^2
        int a = (diff_sum + (diff_square_sum/diff_sum))/2;
        int b = ((diff_square_sum/diff_sum) - diff_sum)/2;
        return {a, b};
    }
};
