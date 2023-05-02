class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negCount=0;
        bool zero=false;
        for(int num:nums)
        {
            if(num==0)
                zero=true;
            else if(num<0)
                negCount++;
        }
        if(zero)
            return 0;
        if(negCount%2==0)
            return 1;
        return -1;
    }
};
