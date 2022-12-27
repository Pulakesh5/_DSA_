class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int left=0, right=n-1;

        while(left<=right)
        {
            while(right>=left && nums[right]==val) right--;
            if(nums[left]==val && right>=left)
            {
                nums[left]=nums[right];
                right--;
            }
            left++;
        }
        return right+1;
    }
};
