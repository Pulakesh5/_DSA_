class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int fp=0,sp=0,k=0;
        while(sp<n)
        {
            while(sp<n && nums[sp]==nums[fp])
            {
                sp++;
            }
            nums[k++]=nums[fp];
            fp=sp;
        }
        return k;
    }
};
