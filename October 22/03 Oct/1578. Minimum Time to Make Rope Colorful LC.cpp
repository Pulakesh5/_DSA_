class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n=colors.size();
        int TotalCost=0,maxCost,cost;
        
        for(int i=1;i<n;i++)
        {
            if(colors[i]!=colors[i-1])
                continue;
            
            cost=time[i-1];
            maxCost=time[i-1];
            while(i<n && colors[i]==colors[i-1])
            {
                cost+=time[i];
                maxCost=max(maxCost,time[i]);
                i++;
            }
            TotalCost=TotalCost+(cost-maxCost);
        }
        
        return TotalCost;
    }
};
