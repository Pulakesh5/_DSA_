class Solution {
public:
    map<pair<int,int>, bool> dp;
    bool check(vector<int> &stones, int index, int jump)
    {  
        int len = stones.size(), gap;
        if(index==(len-1))
        {
            // cout<<"returning true"<<endl;
            return true;
        }
        if(dp.count({index,jump}))
            return dp[{index, jump}];
        for(int i=index+1; i<len; i++)
        {
            gap = stones[i]-stones[index];
            if(gap > (jump+1))
                break;
            if(gap >=(jump-1) && gap<=(jump+1) && check(stones, i, gap))
                return dp[{index, jump}] = true;
        }
        // cout<<index<<" "<<jump<<endl;
        return dp[{index, jump}] = false;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0] != 1)
            return false;
        int index = 1, jump = 1;
        return check(stones, index, jump);
    }
};
