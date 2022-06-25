class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size(),miss=0;
        
        for(int i=1;i<n && miss<=1;i++){
            if(nums[i]<nums[i-1]){
                miss++;
                if(i-2<0 || nums[i-2]<=nums[i]) 
                    nums[i-1]=nums[i];
                else
                    nums[i]=nums[i-1];
            }
        }
        return miss<=1;
    }

};
