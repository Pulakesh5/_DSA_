class Solution{
public:
    vector<int> primes;
    void precompute(){
        int lim = 1299710;
        vector<bool> isPrime(lim,true);
        isPrime[1] = false;
        for(int number = 2; number<=sqrt(lim); number++)
        {
            if(isPrime[number])
            {
                for(int next=number*number; next<lim; next+=number)
                    isPrime[next] = false;
            }
        }
        for(int i=2; i<lim; i++)
            if(isPrime[i])
                primes.push_back(i);
    }
    class disjoint_set{
        int n;
        public:
        int* par;
    
        disjoint_set(int N){
            n=N;
            par=new int[n];
            for(int i=0;i<n;i++){
                par[i]=-1;
            }
        }
        int find(int i){
            if(par[i]<0){
                return i;
            }
            int res=find(par[i]);
            par[i]=res;
            return res;
        }
        bool Union(int i,int j){
            int i_rep=find(i);
            int j_rep=find(j);
            if(i_rep==j_rep) return 0;
            par[i_rep]+=par[j_rep];
            par[j_rep]=i_rep;
            return 1;
        }
    };
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
       if(m==0) return -1;
        disjoint_set* obj=new disjoint_set(n);
        for(int i=1;i<n+1;i++){
            for(auto& j: g[i]){
                obj->Union(i-1,j-1);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if((obj->par[i])<0){
                ans=max(ans,-1*(obj->par[i]));
            }
        }
        return primes[ans-1];
    }
};
