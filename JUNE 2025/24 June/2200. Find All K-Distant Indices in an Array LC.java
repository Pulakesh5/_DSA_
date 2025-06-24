class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        ArrayList<Integer> keyIndex = new ArrayList<>();
        int N = nums.length;
        for(int i=0; i<N; i++)
        {
            if(nums[i]==key)
                keyIndex.add(i);
        }
        
        int last = 0;
        List<Integer> kDistantIndices = new ArrayList<>();
        for(int index:keyIndex)
        {
            for(last=Math.max(last,index-k); last<Math.min(N,index+k+1); last++)
            {    
                kDistantIndices.add(last);
            }
        }

        return kDistantIndices;
    }
}
