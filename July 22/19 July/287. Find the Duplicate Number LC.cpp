class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0,n=nums.size();
       
        while(1){
            if(nums[i]>n) return i;
            nums[i]+=n;
            i=nums[i]%n;
        }
        return -1;
    }
};
