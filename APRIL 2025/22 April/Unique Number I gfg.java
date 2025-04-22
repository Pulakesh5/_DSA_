class Solution {
    public int findUnique(int[] arr) {
        // code here
        int unique = 0;
        for(int num:arr)
            unique ^= num;
        return unique;
    }
}
