class Solution {
public:
    int StringBooltoInt(string str, int k){
        int ans=0,expo=1<<(k-1);
        for(int i=0;i<k;i++){
            if(str[i]=='1')
                ans+=expo;
            expo=expo>>1;
        }
        //cout<<str<<" "<<ans<<'\n';
        return ans;
    }
    bool hasAllCodes(string s, int k) {
        bool contain[1<<k+1];
        memset(contain,false,sizeof(contain));
        int len=s.length();
        string sub;
        for(int i=0;i<=(len-k);i++){
            sub=s.substr(i,k);
            contain[StringBooltoInt(sub,k)]=true;
        }
        
        for(int i=0;i<(1<<k);i++){
            if(!contain[i]){
                //cout<<i;
                return false;
            } 
        }
            
        
        return true;
    }
};
