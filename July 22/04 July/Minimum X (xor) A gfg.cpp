class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int bitCount=__builtin_popcount(b);
        int MSB=63-__builtin_clzll(a);
        int ans=0;
        for(int i=MSB;i>=0 && bitCount;i--){
            if(a&(1<<i)){
                ans |=(1<<i);
                bitCount--;
            }
        }
        if(bitCount){
            for(int i=0;i<32 && bitCount;i++){
                if(!(ans&(1<<i))){
                    ans |=(1<<i);
                    bitCount--;
                }
            }
        }
        
        return ans;
    }
};
