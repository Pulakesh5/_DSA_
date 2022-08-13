class Solution {
public:
    int uniquePaths(int m, int n) {
        // combination of m-1 D and n-1 R moves
       if(m==1 || n==1) return 1;
        m--; 
        n--;
        if(m<n){
            swap(m,n);
        }
        long long j=1,res=1;
        for(int i=m+1;i<=(m+n);i++,j++){
            res*=i;
            res/=j;
        }
        return (int) res;
    }
};
