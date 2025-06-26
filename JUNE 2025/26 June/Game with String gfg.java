class Solution {
    public int minValue(String s, int k) {
        // code here
        int[] freq = new int[26];
        for(char ch:s.toCharArray())
        {
            freq[ch-'a']++;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0; i<26; i++)
        {
            if(freq[i]>0)
                pq.offer(freq[i]);
        }
        
        while(k>0)
        {
            int top = pq.poll();
            if(top>1)
                pq.offer(top-1);
            k--;
        }
        int minVal = 0;
        while(!pq.isEmpty())
        {
            int top = pq.poll();
            minVal += top*top;
        }
        return minVal;
    }
}
