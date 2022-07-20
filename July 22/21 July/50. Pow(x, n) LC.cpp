class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        int pow=abs(n);
        double ans=1.0;
        while(pow){
            if(pow&1)
                ans*=x;
            x=x*x;
            pow/=2;
        }
        
        if(n<0) return 1.0/ans;
        return ans;
    }
};
