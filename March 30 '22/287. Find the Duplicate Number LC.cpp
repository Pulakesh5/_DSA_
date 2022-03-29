class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int ind=0,t;
        while(true){
            if(nums[ind]==-1)
                return ind;
            else{
                t=ind;
                ind = nums[ind];
                nums[t]=-1;
            }
        }
        return -1;
    }
};
