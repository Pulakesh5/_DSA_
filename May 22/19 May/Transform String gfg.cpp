class Solution
{
    public:
    int transform (string A, string B)
    {
        int len_a=A.length(),len_b=B.length();
        if(len_a!=len_b) return -1;
        
        vector<int> vec(256,0);
        int a=len_a-1,b=len_b-1;
        while(a>=0 && b>=0){
            if(A[a]==B[b]){
                a--;
                b--;
            }
            else{
                while(a>=0 && A[a]!=B[b])
                {
                    vec[A[a]]++;
                    a--; 
                }
                if(a>=0){
                    a--;
                    b--;
                }
            }
        }
        int ans=0;
        while(b>=0){
            ans++;
            
            vec[B[b]]--;
            if(vec[B[b]]<0)
                return -1;
            b--;
        }
        
        return ans;
    }
};
