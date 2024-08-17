class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        int len = nums.size();
        vector<long long> productArray(len);
        int zeroCount = 0;
        long long selfProduct = 1ll;
        for(int num:nums)
        {
            if(num==0)
                zeroCount++;
            else
                selfProduct = selfProduct*num;
        }
        if(zeroCount>1)
            return productArray;
        for(int i=0; i<len; i++)
        {
            if(nums[i]==0)
                productArray[i] = selfProduct;
            else if(zeroCount==0)
                productArray[i] = (selfProduct/nums[i]);
        }
        return productArray;
    }
};
