class Solution {
    public int countAtMostK(int arr[], int k) {
        // code here
        Map<Integer,Integer> digitFreq = new HashMap<>();
        int N = arr.length, subarrayCount = 0;
        for(int left=0, right=0; right<N; right++)
        {
            digitFreq.put(arr[right], digitFreq.getOrDefault(arr[right],0)+1);
            while(digitFreq.size()>k)
            {
                if(digitFreq.get(arr[left])>1)
                    digitFreq.put(arr[left], digitFreq.get(arr[left])-1);
                else
                    digitFreq.remove(arr[left]);
                left++;
            }
            subarrayCount += (right-left+1);
        }
        return subarrayCount;
    }
}
