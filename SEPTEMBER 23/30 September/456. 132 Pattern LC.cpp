class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int len = nums.size();
        stack<int> stk;
        int s3 = INT_MIN;
        for(int i=len-1; i>=0; i--)
        {
            if(nums[i]<s3)
                return true;
            else
            {
                while(!stk.empty() && nums[i]>stk.top())
                {
                    s3 = stk.top();
                    stk.pop();
                }
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
