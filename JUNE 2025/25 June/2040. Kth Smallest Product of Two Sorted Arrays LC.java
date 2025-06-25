class Solution {
    void split(int[] nums, ArrayList<Integer> a1, ArrayList<Integer> a2)
    {
        for(int num:nums)
        {
            if(num<0)
                a1.add(-num);
            else
                a2.add(num);
        }
        Collections.reverse(a1);
    }
    public long countLessThanEqual(ArrayList<Integer> a1, ArrayList<Integer> a2, long val)
    {
        long count = 0;
        int N1 = a1.size(), N2 = a2.size();
        for(int i=0, j=N2-1; i<N1; i++)
        {
            while(j>=0 && 1L*a1.get(i)*a2.get(j)>val)
                j--;
            count += (j+1);
        }
        return count;
    }
    public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
        ArrayList<Integer> neg1 = new ArrayList<>();
        ArrayList<Integer> neg2 = new ArrayList<>();
        ArrayList<Integer> pos1 = new ArrayList<>();
        ArrayList<Integer> pos2 = new ArrayList<>();
        
        split(nums1, neg1, pos1);
        split(nums2, neg2, pos2);

        long negativeCount = 1L*neg1.size()*pos2.size() + 1L*neg2.size()*pos1.size();
        long sign = 1;
        if(k>negativeCount)
            k -= negativeCount;
        else
        {
            k = negativeCount - k +1;
            sign = -1;
            ArrayList<Integer> tmp = neg2;
            neg2 = pos2;
            pos2 = tmp;
        }

        long low = 0, high = (long)1e10;
        while(low<high)
        {
            long mid = (low+high)/2;
            if(countLessThanEqual(neg1, neg2, mid) + countLessThanEqual(pos1, pos2, mid) >= k)
                high = mid;
            else
                low = mid+1;
        }
        return sign*low;
    }
}
