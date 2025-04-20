// User function Template for Java
class Solution {
    public int findDuplicate(int[] arr) {
        // code here
        int duplicate = 0;
        int N = arr.length;
        
        for(int i=0; i<N; i++)
        {
            duplicate ^= (i+1);
            duplicate ^= arr[i];
        }
        return duplicate^N;
    }
}
