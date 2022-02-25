class Solution{
public:
    vector<int> primeDivision(int N){
        // code here
        bool prim[10005];
        memset(prim, true, sizeof(prim));
        prim[0]=0;prim[1]=0;
        for(int i=2;i<10001;i++){
            if(prim[i]){
                for(int j=i*i;j<10001;j+=i){
                    prim[j]=false;
                }
            }
        }
        set<int> primes;
        for(int i=2;i<10001;i++){
            if(prim[i])
                primes.insert(i);
        }
        // for(auto it: primes)
        //     cout<<it<<" ";
        // cout<<'\n';
        for(auto it:primes){
            if(primes.find(N-it)!=primes.end())
            {
                 return {it,N-it};
            }
        }
        return {N/2,N/2};
    }
};
