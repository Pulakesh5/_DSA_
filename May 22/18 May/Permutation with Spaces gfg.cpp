class Solution{
public:

    vector<string> permutation(string S){
        if(S.length()==1) return {S};
        int n=S.length();
        
        vector<string> ans;
        string perm;
        for(int p=0;p < 1<<(n-1);p++){
            bitset<10> bit(p);
            string str=bit.to_string();
            perm=S[0];
            for(int i=1;i<n;i++){
                if(str[10-n+i]=='0')
                    perm+=" ";
                perm+=S[i];
            }
            ans.push_back(perm);
            perm.clear();
        }
        
        return ans;
    }
};
