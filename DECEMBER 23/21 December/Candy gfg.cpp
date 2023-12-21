class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        // code here
          
        vector<int> candies(N,1);
        for(int i=1; i<N; i++)
        {
            if(ratings[i]>ratings[i-1])
                candies[i] = candies[i-1]+1;
        }
        int totalCandies=candies[N-1];
        for(int i=N-2; i>-1; i--)
        {
            if(ratings[i]>ratings[i+1])
                candies[i]=max(candies[i], candies[i+1]+1);
            totalCandies+=candies[i];
        }
        return totalCandies;
    }
};
