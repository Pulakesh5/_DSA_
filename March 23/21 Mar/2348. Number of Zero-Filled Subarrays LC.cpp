class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long length=0, count=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                count+=(length*(length+1))/2;
                length=0;
            }
            else
            {
                length++;
            }
        }
        count+=(length*(length+1))/2;
        return count;
    }
};
