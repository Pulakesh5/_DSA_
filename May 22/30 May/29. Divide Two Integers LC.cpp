class Solution {
public:
    int divide(int dividend, int divisor) {
        // dvd=-2^31 & dvs=-1 then ans=2^31 but INT_MAX=2^31-1;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX; 
        
        int sign = (dividend<0 ^ divisor<0 ? -1:1);
        long dvd=labs(dividend),dvs=labs(divisor),ans=0;
        long temp=1,m=1;
        while(dvd>=dvs){
            temp=dvs;m=1;
            while((temp<<1) <= dvd){
                temp<<=1;
                m<<=1;
            }
            dvd-=temp;
            ans+=m;
        }
    
    return sign*ans;
    }
};
