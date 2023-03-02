    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int n=costs.size(), k=costs[0].size();
        
        int INF=1e9;
        
        int prevMinCost = 0;
        int prevSecondMinCost = 0;
        int prevMinColor = -1;
        
        for(int i=0;i<n;i++)
        {
            int currMinCost = INF;
            int currSecondMinCost = INF;
            int currMinColor = -1;
            
            for(int j=0;j<k;j++)
            {
                int cost = costs[i][j];
                if (i == 0) {
                    // initialize prevMinCost and prevSecondMinCost
                    if (cost != 0 && cost < currMinCost) {
                        currSecondMinCost = currMinCost;
                        currMinCost = cost;
                        currMinColor = j;
                    } else if (cost != 0 && cost < currSecondMinCost) {
                        currSecondMinCost = cost;
                    }
                } else {
                    // update dp[i][j]
                    if (j != prevMinColor) {
                        cost += prevMinCost;
                    } else {
                        cost += prevSecondMinCost;
                    }
                    if (cost != 0 && cost < currMinCost) {
                        currSecondMinCost = currMinCost;
                        currMinCost = cost;
                        currMinColor = j;
                    } else if (cost != 0 && cost < currSecondMinCost) {
                        currSecondMinCost = cost;
                    }
                }
            }
            prevMinCost = currMinCost;
            prevSecondMinCost = currSecondMinCost;
            prevMinColor = currMinColor;
        }
        
        if(prevMinCost==INF) return -1;
        return prevMinCost;
    }
