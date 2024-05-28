class Solution {
  public:
    int minimumCost(int n, int Weight, vector<int> &cost) {
        // code here
        const int MAX = 1e8;
        vector<int> prevRow(Weight+5,MAX);
        vector<int> currRow(Weight+5,MAX);
        
        prevRow[0] = 0;
        for(int index=1; index<=n; index++)
        {
            currRow[0] = 0;
            for(int w=0; w<=Weight; w++)
            {
                int noTake = prevRow[w];
                int take = 1e8;
                if(cost[index-1]!=-1 && index<=w)
                    take = cost[index-1] + currRow[w-index];
                currRow[w] = min(take, noTake);
            }
            prevRow = currRow;
        }
        
        if(currRow[Weight]==MAX)
            return -1;

        return currRow[Weight];
    }
};
