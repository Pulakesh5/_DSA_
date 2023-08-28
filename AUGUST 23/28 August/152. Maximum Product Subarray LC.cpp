class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre = 0, suf =0, len = nums.size();
        int maxProduct = nums[0];
        for(int i=0; i<len; i++)
        {
            if(pre==0)//whenever a 0 occurs, restart the prefix subarray
                pre=nums[i];
            else//otherwise keep multiplying
                pre*=nums[i];
            if(suf==0)//whenever a 0 occurs, restart the suffix subarray
                suf =nums[len-1-i];
            else//otherwise keep multiplying
                suf*=nums[len-1-i];
            // cout<<i<<" "<<pre<<" "<<suf<<endl;
            maxProduct = max({maxProduct,pre,suf});//update maxProduct 
        }
        return maxProduct;
    }
};
