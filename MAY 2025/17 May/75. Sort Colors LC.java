class Solution {
    public void sortColors(int[] nums) {
        int red=0, white=0, blue=0;
        for(int num:nums)
        {
            if(num==0)
                red++;
            else if(num==1)
                white++;
            else
                blue++;
        }
        int N = nums.length, index=0;
        while(red>0)
        {
            nums[index++] = 0;
            red--;
        }
        while(white>0)
        {
            nums[index++] = 1;
            white--;
        }
        while(blue>0)
        {
            nums[index++] = 2;
            blue--;
        }
    }
}
