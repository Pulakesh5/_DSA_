/*
    Solution Idea:  what is the condition of not having a solution?
                    Try using Kadane's like algorithm to find the starting station
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),sum=0,tank=0,start=0;
        vector<int> diff(n);
        for(int i=0;i<n;i++)
        {
            diff[i]=gas[i]-cost[i];
            sum+=diff[i];
            tank+=diff[i];
            if(tank<0){
                start=i+1;
                tank=0;
            }
        }

        return sum >= 0 ? start%n :-1 ;
    }
};
