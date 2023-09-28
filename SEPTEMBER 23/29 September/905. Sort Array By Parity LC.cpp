class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd=0, even=0, len = nums.size();
        while(odd<len && even<len)
        {
            while(odd<len)
            {
                if(nums[odd]%2==1)
                    break;
                odd++;
            }
            while(even<len)
            {
                if(nums[even]%2==0)
                    break;
                even++;
            }
            // cout<<"outer : "<<odd<<" "<<even<<endl;
            if(even<len && odd<even)
            {
                // cout<<odd<<" "<<even<<endl;
                swap(nums[odd], nums[even]);
            }
            even++;
        }
        return nums;
    }
};
