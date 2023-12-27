class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minCost=0;
        int len=colors.size();
        char prevColor = colors[0];
        int prevTime=neededTime[0];
        for(int i=1; i<len; i++)
        {
            if(colors[i]==prevColor)
            {
                minCost+= min(prevTime, neededTime[i]);
                prevTime = max(prevTime, neededTime[i]);
            }
            else
                prevTime = neededTime[i];
            prevColor = colors[i];
        }
        return minCost;
    }
};
