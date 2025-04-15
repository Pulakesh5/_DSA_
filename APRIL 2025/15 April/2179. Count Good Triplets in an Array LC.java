class Solution {
    public long goodTriplets(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> pos1 = new HashMap<>();
        int N = nums1.length;
        for(int i=0; i<N; i++)
            pos1.put(nums1[i],i);
        
        long goodTripletCount = 0;
        ArrayList<Integer> pos2 = new ArrayList<>();
        for(int num:nums2)
        {
            int index1 = pos1.get(num);
            int possibleLeftIndices = orderOfKey(pos2, index1);
            int possibleRightIndices = (N-1-index1) - (pos2.size()-possibleLeftIndices); 
            // [n-1 - index] => This denotes possible indices which can occur in the left side of current index in nums2
            // (pos2.size()-possibleLeftIndices) => indices which could have occured in the left side but actually came before index2, so we are subtracting them

            goodTripletCount += (long)(1L*possibleLeftIndices * possibleRightIndices);
            int pos = Collections.binarySearch(pos2, index1);
            if(pos<0)
                pos = -pos-1;
            pos2.add(pos, index1);
        }
        return goodTripletCount;
    }

    private int orderOfKey(ArrayList<Integer> positions, int key)
    {
        int index = Collections.binarySearch(positions, key);
        return (index<0) ? (-index-1):index;
    }
}
