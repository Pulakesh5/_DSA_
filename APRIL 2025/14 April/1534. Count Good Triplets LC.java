class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int N = arr.length;
        int diff_ij, diff_jk, diff_ik, goodTriplet = 0;
        
        for(int i=0; i<(N-2); i++)
        {
            for(int j=i+1; j<(N-1); j++)
            {
                for(int k=j+1; k<N; k++)
                {
                    diff_ij = Math.abs(arr[i]-arr[j]);
                    diff_jk = Math.abs(arr[j]-arr[k]);
                    diff_ik = Math.abs(arr[i]-arr[k]);

                    if(diff_ij<=a && diff_jk<=b && diff_ik<=c)
                        goodTriplet++;
                }
            }
        }
        
        return goodTriplet;
    }
}
