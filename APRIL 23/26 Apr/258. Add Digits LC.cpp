class Solution {
public:
    int sum(int num)
    {
        int digitSum=0;
        while(num)
        {
            digitSum+=(num%10);
            num/=10;
        }
        return digitSum;
    }
    int addDigits(int num) {
        int digitSum=num;
        while(digitSum/10)
        {
            digitSum=sum(digitSum);
        }
        return digitSum;
    }
};
