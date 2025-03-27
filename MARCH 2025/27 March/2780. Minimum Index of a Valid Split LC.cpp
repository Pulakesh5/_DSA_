class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> freq1, freq2;
        for(int num:nums)   
            freq2[num]++;
        
        int n = nums.size();
        int dominant = -1;
        int f1, f2;
        for(int i=0; i<(n-1); i++)
        {
            freq1[nums[i]]++;
            f1 = freq1[nums[i]];
            f2 = freq2[nums[i]] - freq1[nums[i]];

            if(f2>((n-i-1)/2) && f1>((i+1)/2))
                return i;
        }
        return -1;
    }
};
