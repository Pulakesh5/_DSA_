class Solution {
  public:
     long long MOD = 1e9+7;
    vector<vector<long long>> matrixMultiply(vector<vector<long long>> &A, vector<vector<long long>>&B)
    {
        vector<vector<long long>> answer(3,vector<long long>(3,0));
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                for(int k=0; k<3; k++)
                    answer[i][j] = (answer[i][j] + (A[i][k]*B[k][j])%MOD)%MOD;
            }
        }
        return answer;
    }
    vector<vector<long long>> matrixPow(vector<vector<long long>> &mat, int exponent)
    {
        if(exponent==1)
            return mat;
        vector<vector<long long>> product = matrixPow(mat, exponent/2);
        product = matrixMultiply(product, product);
        if(exponent&1)
            product = matrixMultiply(product, mat);
        return product;
    }
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        // code here
        if(n<=2)
            return 1;
        vector<vector<long long>> mat(3,vector<long long>(3,0));
        MOD = m;
        mat[0][0] = a;
        mat[0][1] = b;
        mat[0][2] = 1;
        mat[1][0] = 1;
        mat[2][2] = 1;
        mat = matrixPow(mat,n-2);
        return (mat[0][0]+mat[0][1]+c*mat[0][2])%MOD;
    }
};
