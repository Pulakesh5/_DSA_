//  It's not my own solution
//  But it's a great way to use the concept of sliding pointer 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        for(;j<n;j++)
        {
            if(nums[j]==0) k--;
            if(k<0 && nums[i++]==0) k++;
        }
        return j-i;
    }
};
