class Solution {
    public int minimumOperations(int[] nums) {
        int len = nums.length;
        int[] freq = new int[101];
        for(int i=1; i<=100; i++)
            freq[i] = 0;
            
        if(len%3 == 1)
            freq[nums[len-1]]++;
        else if(len%3 == 2) 
        {
            freq[nums[len-1]]++;
            freq[nums[len-2]]++;
            if(freq[nums[len-1]]>1)
                return (len/3)+1;
        }

        for(int i=(len/3)*3-1; i>=0; i-=3)
        {
            freq[nums[i]]++;
            if(freq[nums[i]]>1)
                return (i+1)/3;

            freq[nums[i-1]]++;
            if(freq[nums[i-1]]>1)
                return (i+1)/3;
            
            freq[nums[i-2]]++;
            if(freq[nums[i-2]]>1)
                return (i+1)/3;
        }
        return 0;
    }
}
