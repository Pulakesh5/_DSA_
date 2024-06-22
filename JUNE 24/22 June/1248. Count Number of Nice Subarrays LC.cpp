class Solution {
private:
    int atMost(vector<int> &nums, int k){
        int i=0, len = nums.size(), count = 0;
        for(int j=0; j<len; j++)
        {
            k-=nums[j]%2;
            while(k<0)
                k+=(nums[i++]%2);
            count += (j-i+1);
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};
