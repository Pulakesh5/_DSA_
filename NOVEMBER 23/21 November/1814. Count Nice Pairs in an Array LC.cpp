class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int count = 0;
        unordered_map<long long, long long> mp;
        int MOD = 1e9+7;
        for(int num:nums)
            count = (count + mp[num - reverse(num)]++)%MOD;
        
        return count;
    }
    int reverse(int num)
    {
        int rev=0;
        while(num)
        {
            rev = rev*10;
            rev = rev + (num%10);
            num/=10;
        }
        return rev;
    }
};
