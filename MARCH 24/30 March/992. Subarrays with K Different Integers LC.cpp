class Solution {
public:
    int atMostK(vector<int> &nums, int k)
    {
        map<int,int> freq;
        int len = nums.size(), count=0;
        for(int i=0,j=0; j<len; j++)
        {
            if(!freq[nums[j]]++)
                k--;
            while(k<0)
            {
                if(!--freq[nums[i]])
                    k++;
                i++;
            }
            count += (j-i+1);
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums,k-1);
    }
};
