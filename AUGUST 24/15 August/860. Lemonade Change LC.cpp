class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int changeOf5 = 0, changeOf10 = 0;
        for(int bill:bills)
        {
            if(bill==5)
                changeOf5++;
            else if(bill==10)
            {
                if(changeOf5==0)
                    return false;
                changeOf5--;
                changeOf10++;
            }
            else if(bill==20)
            {
                if(changeOf10 && changeOf5)
                {
                    changeOf10--;
                    changeOf5--;
                }
                else if(changeOf5>=3)
                {
                    changeOf5-=3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
