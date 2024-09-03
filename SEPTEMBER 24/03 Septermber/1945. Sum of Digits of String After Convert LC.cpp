class Solution {
public:
    int sumOfDigits(int number)
    {
        int sum = 0;
        while(number)
        {
            sum += number%10;
            number /= 10;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        int digitSum = 0, val;
        for(char ch:s)
        {
            val = ch-'a'+1;
            if(val>=10)
                digitSum+=(val/10 + val%10);
            else
                digitSum+=val;
        }
        while(--k)
        {
            digitSum = sumOfDigits(digitSum);
        }
        return digitSum;
    }
};
