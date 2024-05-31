class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int len = nums.size();

        int allxor = 0, preXOR=0;        
        
        for(int i=0; i<len; i++)
            allxor^=nums[i];

        int num1 = 0, num2 = 0;
        for(int bitpos=0; bitpos<32; bitpos++)
        {
            if(allxor&(1<<bitpos))
            {
                for(int i=0; i<len; i++)
                {
                    if(nums[i]&(1<<bitpos))
                        num1^=nums[i];
                    else
                        num2^=nums[i];
                }
                break;
            }
        }
        return {num1, num2};

    }
};
