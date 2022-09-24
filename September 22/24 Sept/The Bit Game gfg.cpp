class Solution{   
public:
    int swapBitGame(long long N){
        // code here 
        int countSetBits=0;
        while(N)
        {
            countSetBits+=(N%2);
            N/=2;
        }
        return (countSetBits%2)?1:2;
    }
};
