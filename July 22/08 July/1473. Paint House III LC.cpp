class Solution {
public:
    int dp[101][101][21];
    int mx=1e7+1;
    
    int rec(vector<int>& houses, vector<vector<int>>& cost, int target, int index, int count, int prev){
          
        if(index==houses.size()) return (count==target?0:mx);
        if(index>houses.size()) return mx;
        
        if(dp[index][count][prev]!=-1) return dp[index][count][prev];
        
        int minCost=mx;
        
        if(houses[index]){
            if(houses[index]!=prev)
                minCost = rec(houses, cost, target, index+1, count+1, houses[index]);
            else
                minCost = rec(houses, cost, target, index+1, count, houses[index]);
        }
        else{
            int n=cost[0].size();
            for(int j=0;j<n;j++){
                int temp;
                if((j+1)!=prev) 
                    temp = cost[index][j] + rec(houses, cost, target, index+1, count+1, j+1);
                else
                    temp = cost[index][j] + rec(houses, cost, target, index+1, count, j+1);
                minCost=min(minCost,temp);
            }
        }
        
        return dp[index][count][prev] = minCost;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        
        //index, count, prev
        int ans=rec(houses, cost, target, 0, 0, 0);
        
        return ans==mx?-1:ans;
    }
};
