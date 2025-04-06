class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int N = nums.length;
        int[] subsetSize = new int[N+5];
        int[] last = new int[N];

        Arrays.fill(subsetSize, 1);
        
        Arrays.sort(nums);
        int maxSubsetSize = 1, subsetLastIndex=0;
        for(int i=0; i<N; i++)
        {
            last[i] = i;
            for(int j=0; j<i; j++)
            {
                if(nums[i]%nums[j]==0 && subsetSize[i]<subsetSize[j]+1)
                {
                    subsetSize[i] = subsetSize[j]+1;
                    last[i] = j;
                }
            }
            if(subsetSize[i]>maxSubsetSize)
            {
                maxSubsetSize = subsetSize[i];
                subsetLastIndex = i;
            }
        }
        

        List<Integer> subset = new ArrayList<>();
        while(subsetLastIndex!=last[subsetLastIndex])
        {
            subset.add(nums[subsetLastIndex]);
            subsetLastIndex = last[subsetLastIndex];
        }

        subset.add(nums[subsetLastIndex]);
        Collections.reverse(subset);
        
        return subset;
    }
}
