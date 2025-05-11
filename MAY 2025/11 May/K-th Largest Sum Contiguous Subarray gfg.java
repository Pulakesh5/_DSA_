class Solution {
    public static int kthLargest(int[] arr, int k) {
        // code here
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int N = arr.length;
        int[] prefixSum = new int[N+1];
        for(int i=0; i<N; i++)
        {
            prefixSum[i+1] = prefixSum[i]+arr[i];
            pq.add(arr[i]); // putting sum of subarray with one element
            if(pq.size()>k)
                pq.poll();
        }
        
        for(int i=1; i<N; i++)
        {
            for(int j=i+1; j<=N; j++)
            {
                pq.add(prefixSum[j]-prefixSum[i-1]);
                if(pq.size()>k)
                    pq.poll();
            }
        }
        return pq.poll();
    }
}
