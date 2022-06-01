class Solution{
public:
    vector<int> TOH(int N, int n, int from, int to, int aux){
        int half=1<<(N-1);
        if(N==1 || n==half)
            return {from,to};
        else{
            if(n<half)
                return TOH(N-1, n, from, aux, to);
            else
                return TOH(N-1,n%half ,aux , to, from);
        }
    }
    vector<int> shiftPile(int N, int n){
        // code here
        return TOH(N,n,1,3,2);
    }
};
