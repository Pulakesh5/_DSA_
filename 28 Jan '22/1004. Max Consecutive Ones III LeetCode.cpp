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

//Easy to read and understand
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0,n=nums.size();
        int zero=0,ans=0;
        for(; right < n; right++){
            if(nums[right]==0)
                zero++;
            if(zero > k ){
                if(nums[left]==0)
                    zero--;    
                left++;
            }
            else
                ans=max(ans,right-left+1);
        }
        return ans;
    }
};
