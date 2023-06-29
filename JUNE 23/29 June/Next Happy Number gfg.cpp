lass Solution{
public:
    int sumOfSqDigits(int number)
    {
        long long sum = 0, digit;
        while(number>0)
        {
            digit = number%10;
            sum = sum + (digit*digit);
            number= number/10;
        }
        return sum;
    }
    bool check(int number, set<int> &cyclicNumbers)
    {
        int sum ;   
        while(1)
        {
            sum = sumOfSqDigits(number);
            if(sum==1)
                return true;
            if(cyclicNumbers.find(sum)!=cyclicNumbers.end())
                return false;
            number = sum;
        }
        return false;
        
    }
    int nextHappy(int N){
        // code here
        set<int> cyclicNumbers = {4, 16, 37, 58, 89, 145, 42, 20};
        int happyNumber = N+1;
        
        while(1)
        {
            if(check(happyNumber, cyclicNumbers)==true)
                return happyNumber;
            else
                happyNumber++;
        }
        return -1;
        
    }
};
