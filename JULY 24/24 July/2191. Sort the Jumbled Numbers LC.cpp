class Solution {
public:
    static int convert(int num, vector<int> &mapping)
    {
        if(num==0)
            return mapping[0];
        int ex = 0;
        for(int pow10=1; num; pow10*=10)
        {
            auto [q, r] = div(num, 10);
            ex+=mapping[r]*pow10;
            num = q;
        }
        return ex;
    }
    static vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> mapNum(N,vector<int>(2));

        for(int i=0; i<N; i++)
        {
            mapNum[i] = {convert(nums[i], mapping), i};
        }

        sort(mapNum.begin(), mapNum.end());
        vector<int> ans(N);
        for(int i=0; i<N; i++)
            ans[i] = nums[mapNum[i][1]];
        return ans;
    }
};
