class Solution {
    public int totalElements(int[] arr) {
        // code here
        int N = arr.length;
        Map<Integer, Integer> distinct = new HashMap<>();
        int maxLen = 1;
        for(int left = 0, right = 0; right<N; right++)
        {
            distinct.put(arr[right], distinct.getOrDefault(arr[right],0)+1);
            while(distinct.size()>2)
            {
                if(distinct.get(arr[left])>1)
                    distinct.put(arr[left], distinct.getOrDefault(arr[left],0)-1);
                else
                    distinct.remove(arr[left]);
                left++;
            }
            maxLen = Math.max(maxLen, right-left+1);
        }
        return maxLen;
    }
}
