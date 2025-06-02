class Solution {
    public int candy(int[] ratings) {
        int N = ratings.length;
        int[] candies = new int[N];
        Arrays.fill(candies, 1);
        // forward pass
        for(int i=1; i<N; i++)
        {
            if(ratings[i]>ratings[i-1])
                candies[i] = candies[i-1]+1;
        }
        // backward pass
        int totalCandies = candies[N-1];
        for(int i=N-2; i>=0; i--)
        {
            if(ratings[i]>ratings[i+1])
                candies[i] = Math.max(candies[i], candies[i+1]+1);
            totalCandies += candies[i];
        }

        return totalCandies;
    }
}
