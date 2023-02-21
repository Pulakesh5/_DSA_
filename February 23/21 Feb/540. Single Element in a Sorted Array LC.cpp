class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xr=0;
        for(int num:nums)
            xr=xr^num;
        return xr;
    }
};
