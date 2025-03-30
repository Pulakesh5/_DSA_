/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int n = gas.size();
        int sumOfDiff = 0;
        int tank = 0, start = 0;
        for(int i=0; i<n; i++)
        {
            sumOfDiff += (gas[i]-cost[i]);
            tank += (gas[i]-cost[i]);
            if(tank<0)
            {
                tank = 0;
                start = i+1;
            }
        }
        return sumOfDiff>=0? start%n : -1;
    }
};
