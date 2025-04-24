class Solution {
    public int getSingle(int[] arr) {
        // code here
        int[] bitCount = new int[32];
        for(int num:arr)
        {
            for(int i=0; i<32; i++)
            {
                if((num&(1<<i)) != 0)
                    bitCount[i]++;
            }
        }
        int single = 0;
        for(int i=0; i<32; i++)
        {
            if(bitCount[i]%3==1)
                single += (1<<i);
        }
        return single;
    }
}
