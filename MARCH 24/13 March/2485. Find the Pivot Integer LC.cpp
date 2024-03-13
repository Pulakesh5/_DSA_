class Solution {
public:
    int pivotInteger(int n) {
        long long x;
        long long l=1, h=n;
        long long nSum = (1ll*n*(n+1))/2;
        while(l<=h)
        {
            x = (l+h)/2;
            if(x*x == nSum)
                return x;
            else if((x*x)<nSum)
                l = x+1;
            else 
                h = x-1;
        }
        return -1;
    }
    // (x(x+1))/2 = (n*(n+1))/2-(x*(x-1))/2
    // => x^2 = (n*(n+1))/2

};
