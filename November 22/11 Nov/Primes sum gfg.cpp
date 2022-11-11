class Solution {
public:
    bool isPrime(int num)
    {
        if(num<=1) return false;
        
        if(num<=3) return true;
        
        if((num&1)==0) return false;
        
        for(int i=3;i<=sqrt(num);i++)
        {
            if((num%i)==0) return false;
        }
        return true;
    }
    string isSumOfTwo(int N){
        // code here
        if(isPrime(N-2)) return "Yes";
        
        for(int i=3;i<=(N/2);i+=2)
        {
            if(isPrime(i) && isPrime(N-i)) return "Yes";
        }
        
        return "No";
    }
};
