class Solution {
    public int maxRemoval(int[] nums, int[][] queries) {
        int N = nums.length;
        int NQ = queries.length;
        Arrays.sort(queries, (a,b)->a[0]-b[0]);
        PriorityQueue<Integer> endings = new PriorityQueue<>();
        int[] endMarker = new int[N+1];
        int iq=0, currOperation=0;
        for(int i=0; i<N; i++)
        {
            currOperation -= endMarker[i]; // remove those operations which has ended before i-th index
            while(iq<NQ && queries[iq][0]<=i) // considering all the queries that has started before or at i
            {
                endings.offer(-1*queries[iq][1]); // -1 because priority queue by default is minHeap in JAVA
                iq++;
            }

            while(currOperation < nums[i])
            {
                if(endings.isEmpty() || -endings.peek()<i)
                {
                    return -1; // we don't enough operations to make i-th num 0 
                }
                endMarker[-endings.poll()+1]++;
                currOperation++;
            }
        }
        return endings.size(); //priority queue size denotes those end markers which are being used for making array zero
    }
}
