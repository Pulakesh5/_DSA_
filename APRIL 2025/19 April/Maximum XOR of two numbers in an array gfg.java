class Solution {
    public int maxXor(int[] arr) {
        // code here
        // find max prefix of XOR-ed bits which forms max xor
        int mask = 0, maxXOR = 0;
        for(int bit=31; bit>=0; bit--)
        {
            mask = mask | (1<<bit);
            Set<Integer> prefix = new HashSet<>();
            
            for(int num:arr)
                prefix.add(mask&num);
            
            int tmp = maxXOR | (1<<bit);
            for(int pref:prefix)
            {
                if(prefix.contains(tmp^pref))
                {
                    maxXOR = tmp;
                    break;
                }
            }
        }
        return maxXOR;
    }
}
