class Solution {
public:
    int minSteps(int n) {
        if(n==1)
            return 0;
        if(n<=5)
            return n;

        vector<int> operation(n+5,n+1);
        operation[2] = 2;
        operation[3] = 3;
        for(int i=2; i<=n; i++)
        {
            if(operation[i]==(n+1))
                operation[i] = i;
            // cout<<i<<" "<<endl;
            for(int j=2*i; j<=n; j+=i)
            {
                operation[j] = min(operation[i]+j/i, operation[j]);
            }
            // cout<<endl;
        }
        return operation[n];
    }
};
