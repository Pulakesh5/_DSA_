class Solution {
    public int numRabbits(int[] answers) {
        int[] freq = new int[1001];
        for(int same:answers)
            freq[same+1]++;
        int ans = 0;
        for(int i=1; i<1001; i++)
        {
            ans += ((freq[i]+i-1)/i)*i;
        }
        return ans;
    }
}
