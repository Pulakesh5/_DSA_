class Solution{
public:
    string LCP(string ar[], int n)
    {
        if(n==1) return ar[0];
        
        int len= INT_MAX;
        
        for(int i=0;i<n;i++)
            len=min(len,(int)sizeof(ar[i]));
        string ans="";
        for(int i=0;i<len;i++){
            char ch=ar[0][i];
            for(int s=1;s<n;s++){
                if(ar[s][i]!=ch){
                    if(i==0) return "-1";
                    else return ans;
                }
            }
            ans+=ch;
        }
        
        return ans;
    }
};
