class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int MOD = 1e7;
        int len = nums.size(), next = nums[0];
        for(int i=0; i<len; i++)
        {
            next = nums[i]%len;
            nums[next]+=len;
            if(nums[next]/len>1)
                return next;
            // for(int j=0; j<5; j++)
            //     cout<<nums[j]<<" ";
            // cout<<endl;
        }
        return -1;
    }
};
