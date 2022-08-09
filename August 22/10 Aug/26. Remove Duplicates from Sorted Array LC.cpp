class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size(),j=0;
        for(int i=0;i<n;i++){
            while((i+1)<n && nums[i+1]==nums[i])
                i++;
            if(i<n) nums[j++]=nums[i];
        }
        return j;
    }
};
