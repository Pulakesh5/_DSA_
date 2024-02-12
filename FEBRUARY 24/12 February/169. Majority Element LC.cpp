class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int majElmnt=nums[0];
        int majCnt = 1, mx=1;
        for(int i=1; i<len; i++)
        {
            if(majCnt==0)
            {
                majCnt = 1;
                majElmnt = nums[i];
            }
            else if(nums[i]==majElmnt)
                majCnt++;
            else
                majCnt--;
        }
        return majElmnt;
    }
};
