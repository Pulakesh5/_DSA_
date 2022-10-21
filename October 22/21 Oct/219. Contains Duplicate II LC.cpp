class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mp_pos;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp_pos.find(nums[i])!=mp_pos.end() && (i-mp_pos[nums[i]])<=k) return true;
            mp_pos[nums[i]]=i;
        }
        return false;
    }
};
