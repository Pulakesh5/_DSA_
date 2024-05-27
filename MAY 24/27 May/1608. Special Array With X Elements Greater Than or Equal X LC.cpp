class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i=0; i<=len; i++)
        {
            int count = len - (lower_bound(nums.begin(), nums.end(), i) - nums.begin());
            if(count==i)
                return count;
        }

        return -1;
    }
};
