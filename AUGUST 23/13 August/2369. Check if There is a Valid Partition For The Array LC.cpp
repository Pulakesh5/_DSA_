class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int len = nums.size();
        vector<bool> dp(len+2, false);

        dp[2] = nums[0]==nums[1];
        if(len==2) //if length is 2, return from here
            return dp[2];
            
        dp[3] = nums[0]==nums[1] && nums[1]==nums[2]; //checking if first 3 elements are same or not
        dp[3] = dp[3] | (nums[0]+1==nums[1] && nums[1]+1==nums[2]); //checking if first 3 elements are consecutive or not
        
        if(len==3) // if length is 3, return from here 
            return dp[3];
        
        for(int i=4; i<=len; i++)
        {
            //checking if last 2 elements are same or not
            dp[i] = dp[i-2] && (nums[i-1]==nums[i-2]); 
            //checking if last 3 elements are same or not
            dp[i] = dp[i] || (dp[i-3] && (nums[i-1]==nums[i-2] && nums[i-2]==nums[i-3])); 
            //checking if last 3 elements are consecutive or not
            dp[i] = dp[i] || (dp[i-3] && (nums[i-1]==nums[i-2]+1 && nums[i-2]==nums[i-3]+1)); 
        }

        return dp[len];
    }
};
