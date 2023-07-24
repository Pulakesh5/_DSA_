class Solution {
public:
    double my(double x, int n)
    {
        // cout<<n<<"\n";
        if(n==0)
            return 1.0;
        if(n==1)
            return x;
        if(n==-1)
            return (1/x);
        // cout<<endl;
        double half = my(x,n/2);
        
        half = (1.00*half * half);
        // cout<<n<<" "<<half<<endl;

        if(n%2 == 0)
            return half;
        else if(n<0)
            return ((1/x)*half);
        return (x*half);
    }
    double myPow(double x, int n) {
        double ans = my(x,n);
        return ans;
    }
};
