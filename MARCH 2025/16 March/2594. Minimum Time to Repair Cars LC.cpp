class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        
        map<int,long long> rankCount;
        int minRank = INT_MAX, maxRank = INT_MIN;
        for(int rank:ranks)
        {
            rankCount[rank]++;
            if(rank<minRank)
                minRank = rank;
            else if(rank>maxRank)
                maxRank = rank;
        }
        long long low = 1, high = (1ll*cars*cars)*minRank;
        long long minTime = high, time;
        while(low<high)
        {
            time = (low+high)/2;
            long long carsRepaired = 0;
            for(auto it:rankCount)
            {
                carsRepaired += (it.second)*(long long)sqrt(time/it.first);
                if(carsRepaired>=cars)
                    break;
            }
            if(carsRepaired>=cars)
            {
                high = time;
            }
            else
                low = time+1;
        }
        return low;
    }
};
