class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        constexpr  int N{100'000};
        vector<bool> exists(N+1,false);
        for(int num:nums)
            exists[num] = true;

        int ans = 0, len = nums.size();
        long long num;
        int longestStreak = -1;
        for(int i=0; i<len; i++) {
            num = nums[i];
            if(exists[num]==false)
                continue;
            int length = 0;
            while(num<N && exists[num])
            {
                length++;
                num = num*num;
            }
            if(length>1)
                longestStreak = max(longestStreak, length);
        }
        return longestStreak;
    }
};
