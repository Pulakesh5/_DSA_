int minChar(string str){
        //Write your code here
        string s = str+ "#";
        reverse(str.begin() , str.end());
        s = s+str;
        int n = s.size();
        int lps[n];
        lps[0]=0;
        int len=0;
        int i=1;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        return str.size()-lps[n-1];
    }
