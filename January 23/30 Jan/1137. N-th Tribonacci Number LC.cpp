class Solution {
public:
    int tribonacci(int n) {
        int x_0 = 0,x_1 = 1, x_2 = 1;
        
        if(n<=2) return (n==0? 0: 1);
        n-=2;
        while(n--)
        {
            x_2+=x_1+x_0;
            x_1=(x_2-x_1-x_0);
            x_0=(x_2-x_1-x_0);
        }
        return x_2;
    }
};
