class Solution {
    public long countGood(int[] nums, int k) {
        long goodSubarrayCount = 0;
        Map<Integer,Long> frequency = new HashMap<>();
        int N = nums.length;
        int key, pairCount = 0;
        for(int left = 0, right=0; right<N; right++)
        {
            key = nums[right];
            frequency.put(key, frequency.getOrDefault(key,0L)+1);
            pairCount += (frequency.get(key)-1);
            
            if(pairCount>=k)
            {
                goodSubarrayCount += (N-right);
                while(left<right && pairCount>=k)
                {
                    key = nums[left++];
                    frequency.put(key, frequency.get(key)-1);
                    pairCount -= frequency.get(key);
                    if(pairCount>=k)
                        goodSubarrayCount += (N-right);
                }
            }
        }
        return goodSubarrayCount;
    }
}
