class Solution {
public:
    int lower_bound(vector<vector<int>> &vec,int worker)
    {
        int l=0, h=vec.size()-1;
        int index, lb;
        while(l<=h)
        {
            index = (l+h)/2;
            if(vec[index][0]<=worker)
            {
                lb = index;
                l = index+1;
            }
            else
                h = index-1;
        }
        return lb;
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int len = worker.size();
        vector<vector<int>> diff_profit_pairs(len);

        for(int i=0; i<len; i++)
            diff_profit_pairs[i] = {difficulty[i], profit[i]};
        sort(diff_profit_pairs.begin(), diff_profit_pairs.end());
        for(int i=1; i<len; i++)
        {
            diff_profit_pairs[i][1] = max(diff_profit_pairs[i-1][1], diff_profit_pairs[i][1]);
        }
        int totalProfit = 0, lb;

        for(int i=0; i<len; i++)
        {
            lb = lower_bound(diff_profit_pairs, worker[i]);
            if(lb < 0 || lb>=len)
                continue;
            totalProfit += diff_profit_pairs[lb][1];
        }
        return totalProfit;
    }
};
