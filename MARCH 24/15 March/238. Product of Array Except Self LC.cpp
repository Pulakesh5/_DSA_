class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        int n = nums.size();
        vector<int> productNums(n);
        long long product=1;
        int zeroIndex = -1;
        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
            {
                zeroCount++;
                zeroIndex = i;
            }
            else
                product = product*nums[i];
        }
        if(zeroCount==1)
            productNums[zeroIndex] = product;
        else if(zeroCount==0)
        {
            for(int i=0; i<n; i++)
            {   
                productNums[i] = product/nums[i];
            }
        }
        
        return productNums;
    }
};
