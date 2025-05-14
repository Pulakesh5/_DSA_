class Solution {
    long MOD = (long)(1e9+7);
    public void matrixMultiplication(long[][] A, long[][] B)
    {
        long[][] ans = new long[26][26];
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<26; j++)
            {
                for(int k=0; k<26; k++)
                    ans[i][j] = (ans[i][j]+ (A[i][k]*B[k][j])%MOD) %MOD;
            }
        }
        for(int i=0; i<26; i++)
            A[i] = ans[i].clone();
    }
    public long[][] matrixExponentiation(long[][] matrix, int expo)
    {
        long[][] ans = new long[26][26];
        for(int i=0; i<26; i++)
            ans[i][i] = 1;
        while(expo>0)
        {
            if((expo%2)==1)
                matrixMultiplication(ans, matrix);
            matrixMultiplication(matrix, matrix);
            expo = expo/2;
        }
        return ans;
    }
    public int lengthAfterTransformations(String s, int t, List<Integer> nums) {
        // considering example 2 
        // f[n][0] = 0+0+..+f[n-1][24]+f[n-1][25]
        // f[n][1] = f[n-1][0]+0+..+0+f[n-1][25]
        // .         .
        // .         .
        // f[n][25] = 0+0+..+f[n-1][23]+f[n-1][24]+0
        // f[n] = M*f[n-1] = M*M*f[n-2] = M^(n-1)*f[0] where f[0] is the initial count of character in the string "s"
        long[][] scalerMatrix = new long[26][26];
        for(int i=0; i<26; i++)
        {
            for(int j=nums.get(i); j>0; j--)
                scalerMatrix[(j+i)%26][i]++;
        }

        int[] f0 = new int[26];
        for(char ch:s.toCharArray())
            f0[ch-'a']++;
        
        long[][] finalMatrix = matrixExponentiation(scalerMatrix, t);
        long[] fn = new long[26];
        long totalCharacter = 0;
        for(int i=0; i<26; i++)
        {
            for(int j=0; j<26; j++)
                fn[i] = (fn[i]+(finalMatrix[i][j]*f0[j])%MOD)%MOD;
            totalCharacter = (totalCharacter + fn[i])%MOD;
        }
        return (int)totalCharacter;
    }
}
