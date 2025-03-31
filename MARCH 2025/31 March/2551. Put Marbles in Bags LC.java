class Solution {
    public long putMarbles(int[] weights, int k) {
        // splitting the marbles in k groups is like choosing k-1 boundaries
        
        // Now assume this is the split for minimum score
        // [0..i | i+1...j | j+1...k | k+1...n-1]
        // what is the minimum score here MIN_SCORE = (0+i) + (i+1+j) + (j+1+k) + (k+1+n-1)
        // In other words, MIN_SCORE = 0 + (i+(i+1)) + (j+(j+1)) + (k+(k+1)) + n-1
        
        // Similarly, lets assume the split for maximum score is this
        // [0..p | p+1...q | q+1...r | r+1...n-1]
        // here MAX_SCORE = (0+p) + (p+1+q) + (q+1+r) + (r+1+n-1)
        // In other words, MIN_SCORE = 0 + (p+(p+1)) + (q+(q+1)) + (r+(r+1)) + n-1

        // Here comes the Eureka moment
        // MAX_SCORE - MIN_SCORE = {(p+(p+1)) + (q+(q+1)) + (r+(r+1))} - {(i+(i+1)) + (j+(j+1)) + (k+(k+1))}

        // Now the solution is pretty straight-forward

        List<Long> boundaries = new ArrayList();
        int N = weights.length;

        for(int i=0; i<(N-1); i++)
            boundaries.add((Long)((long)weights[i] + (long)weights[i+1]));
        
        Collections.sort(boundaries);

        System.out.print(boundaries);

        Long MAX_MIN_DIFF_SCORE = 0L;
        for(int i=0; i<(k-1); i++)
        {
            MAX_MIN_DIFF_SCORE += (boundaries.get(N-2-i) - boundaries.get(i));
        }
        return MAX_MIN_DIFF_SCORE;
    }
}
