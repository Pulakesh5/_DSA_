class Solution {
    static int longestSubarray(int[] arr, int k) {
        // Code Here
        Map<Integer,Integer> countIndex = new HashMap<>();
        int count = 0;
        int longestSubarrayLength=0;
        for(int i=0; i<arr.length; i++)
        {
            count += (arr[i]>k?1:0);
            count -= (arr[i]<=k?1:0);
            if(!countIndex.containsKey(count))
                countIndex.put(count, i);
            if(count>0)
                longestSubarrayLength = i+1;
            else if(count<=0 && countIndex.containsKey(count-1))
                longestSubarrayLength = Math.max(longestSubarrayLength, i-countIndex.get(count-1));
        }
        return longestSubarrayLength;
    }
}
