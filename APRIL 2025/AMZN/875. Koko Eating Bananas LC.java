class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        long left = 1L, right = 1L*Arrays.stream(piles).max().getAsInt();
        long time, speed, N = piles.length;
        while(left<right) {
            speed = (left+right)/2;
            time = 0;
            for(int i=0; i<N; i++) {
                time += (piles[i]+speed-1)/speed;
            }
            if(time>h)
                left = speed+1;
            else
                right = speed;
        }
        return (int)right;
    }
}
