// n    a   b   c
// 2    1   1   0
// 3    2   1   1
// 4    4   2   1

class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        long long a = 1, b = 1, c = 0;
        if(n<=2)
            return 1;
        // cout<<2<<" : "<<a<<" "<<b<<" "<<c<<endl;
        for(int i=3; i<=n; i++)
        {
            a = a + b + c;
            b = a - b - c;
            c = a - b - c;
            // cout<<i<<" : "<<a<<" "<<b<<" "<<c<<endl;
        }
        return a;
    }
};
