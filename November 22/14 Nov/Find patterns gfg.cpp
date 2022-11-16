
class Solution{   
public:
    // int numberOfSubsequences(string S, string W){
    //     // code here 
    //     int ns=S.size(),nw=W.size();
    //     int occurence=0;
    //     bool flag=true;
        
    //     for(int i=0;i<ns;i++)
    //     {
    //         flag=true;
    //         for(int j=0;j<nw && (i+j)<ns;j++)
    //         {
    //             if(S[i+j]==W[j]) continue;
    //             flag=false;
    //             break;
    //         }
    //         occurence+=flag;
    //         cout<<i<<" ";
    //         if(flag) i+=(nw-1);
    //     }
    //     cout<<endl;
    //     return occurence;
    // }
    
    int fun(string &s, string &t, int i, int j){
        if(j >= t.size()) return 1;
        if(i >= s.size()) return 0;
         if(s[i] == t[j]){
             s[i] = '#';
             return fun(s, t, i + 1, j + 1);
         } 
         return fun(s, t, i + 1, j);
    }
    
    public:
    
    int numberOfSubsequences(string S, string W){
        int res = 0;
        for(int i = 0; i < S.size() && S.size() - i >= W.size(); i++){
            res += fun(S, W, i, 0);
        }
        return res;
    }
};
