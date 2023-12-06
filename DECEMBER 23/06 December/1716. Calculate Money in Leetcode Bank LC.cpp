class Solution {
public:
    int totalMoney(int n) {
        int sumMoney = 0;
        int prevMonday=0, prev=0;
        int day=1;
        while(day<=n)
        {
            if(day%7==1)
            {
                sumMoney+=(++prevMonday);
                prev = prevMonday;
            }
            else
                sumMoney+=(++prev);
            day++;
        }
        return sumMoney;
    }
};
