class Solution
{
    private static int countLessThanEqual(int[][] mat, int n, int mid) {
        int row = 0, col = n-1, count = 0;
        while(row<n && col>=0) {
            if(mat[row][col]>mid)
                col--;
            else{
                count += (col+1);
                row++;
            }
        }
        return count;
    }
	
	public static int kthSmallest(int[][]mat,int n,int k)
	{
        //code here.
        int low = mat[0][0], high = mat[n-1][n-1];
        int mid, count;
        
        while(low<high) {
            mid = (low+high)/2;
            count = countLessThanEqual(mat, n, mid);
            if(count<k)
                low = mid+1;
            else
                high = mid;
        }
        return high;
    }
}
