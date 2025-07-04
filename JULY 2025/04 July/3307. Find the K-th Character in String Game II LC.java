class Solution {
    public char kthCharacter(long k, int[] operations) {
        // 1010
        // if i-th bit is set and operations[i] is 1, then in the final answer character will be shifted by 1 
        int shift = 0;
        for(int i=(int)(Math.log(k)/Math.log(2)); i>=0; i--)
        {
            if(k>(1l<<i))
            {
                k -= (1l<<i);
                shift += operations[i];
            }
        }
        return (char)('a'+shift%26);
    }
}
