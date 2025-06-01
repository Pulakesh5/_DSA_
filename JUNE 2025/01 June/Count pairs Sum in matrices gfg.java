class Solution {
    int countPairs(int[][] mat1, int[][] mat2, int x) {
        // code here
        int N = mat1.length;
        int index1 = 0, index2=N*N-1;
        int x_sumPairCount = 0, sum;
        
        while(index1<(N*N) && index2>=0)
        {
            sum = mat1[index1/N][index1%N] + mat2[index2/N][index2%N];
            if(sum>x)
                index2--;
            else if(sum<x)
                index1++;
            else
            {
                index2--;
                index1++;
                x_sumPairCount++;
            }
        }
        return x_sumPairCount;
    }
}
