class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<long long, int> lastPos;
        lastPos[0] = -1;
        int len = nums.size();
        long long sum = 0;
        for(int i=0; i<len; i++)
        {
            sum+=nums[i];
            if(lastPos.find(sum%k)==lastPos.end())
            {
                lastPos[sum%k] = i;
            }
            else
            {
                if(i-lastPos[sum%k]>=2)
                    return true;
            }
        }
        return false;
    }
};
