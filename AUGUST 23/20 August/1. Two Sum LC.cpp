class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int len = nums.size();
        vector<pair<int,int>> vp(len);
        for(int i=0; i<len; i++) vp[i] = {nums[i],i};
        sort(vp.begin(), vp.end());
        int l=0, r=nums.size()-1, sum;
        while(l<r)
        {
            sum = vp[l].first + vp[r].first;
            if(sum==target)
                return {vp[l].second,vp[r].second};
            else if(sum<target)
                l++;
            else
                r--;
        }
        return {-1,-1};
    }
};
