class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
        Map<Integer,Integer> countMod = new HashMap<>();
        countMod.put(0,1);
        int count = 0;
        long countOfInterestingSubarray = 0L;
        for(int num:nums)
        {
            if(num%modulo == k)
                count = (count+1)%modulo;
            
            countOfInterestingSubarray += countMod.getOrDefault((count-k+modulo)%modulo,0);
            countMod.put(count, countMod.getOrDefault(count,0)+1);
        }
        return countOfInterestingSubarray;
    }
}
