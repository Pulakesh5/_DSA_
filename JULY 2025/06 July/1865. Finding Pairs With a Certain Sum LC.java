class FindSumPairs {
    Map<Integer,Integer> freq = new HashMap<>();
    int[] arr1, arr2;

    public FindSumPairs(int[] nums1, int[] nums2) {
        this.arr1 = nums1;
        this.arr2 = nums2;
        for(int num:nums2)
            updateFreq(num, 1);
    }
    public void updateFreq(int num, int val)
    {
        freq.put(num, freq.getOrDefault(num,0)+val);
    }
    public void add(int index, int val) {
        updateFreq(arr2[index], -1);
        arr2[index] += val;
        updateFreq(arr2[index], 1);
    }
    
    public int count(int tot) {
        int ans = 0;
        for(int num:arr1)
        {
            ans += freq.getOrDefault(tot-num,0);
        }
        return ans;
    }
}

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs obj = new FindSumPairs(nums1, nums2);
 * obj.add(index,val);
 * int param_2 = obj.count(tot);
 */
