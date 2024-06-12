class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countZero=0, countOne=0, countTwo=0;
        for(int num:nums)
        {
            if(num==0)
                countZero++;
            else if(num==1)
                countOne++;
            else
                countTwo++;
        }
        int k=0;
        while(countZero--)
            nums[k++] = 0;
        while(countOne--)
            nums[k++] = 1;
        while(countTwo--)
            nums[k++] = 2;
    }
};
