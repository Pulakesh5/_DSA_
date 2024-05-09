class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        int len = happiness.size(), reduce=0;
        long long totalHappiness=0ll;
        for(int i=0; i<len && k; i++, k--, reduce++)
        {
            if(happiness[i]-reduce>0)
                totalHappiness+=(happiness[i]-reduce);
            else
                break;
        }
        return totalHappiness;
    }
};
