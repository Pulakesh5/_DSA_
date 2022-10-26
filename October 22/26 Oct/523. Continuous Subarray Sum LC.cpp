class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> remPos;
        remPos[0]=0;
        int sum=0, n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=(nums[i]);
            
            if(!remPos.count(sum%k))
                remPos[sum%k]=i+1;
            else if(remPos[sum%k]<i)
                return true;
        }
        return false;
    }
};
