class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int length = mat.size();
        long long diagonalSum=0;
        for(int i=0;i<length;i++)
            diagonalSum +=mat[i][i];
        for(int i=0;i<length;i++)
            diagonalSum+=mat[i][length-1-i];
        if(length%2)
            diagonalSum-=mat[length/2][length/2];
        return diagonalSum;
    }
};
