class Solution {
public:
    int romanToInt(string s) {
        int n=s.length();
        int num=0;
        map<char,int> roman;
        roman['I']=1;
        roman['X']=10;
        roman['C']=100;
        roman['M']=1000;
        roman['V']=5;
        roman['L']=50;
        roman['D']=500;
            
        for(int i=0;i<n;i++){
            if((i+1)<n){
                if(s[i]=='I' && (s[i+1]=='V' || s[i+1]=='X'))
                    num-=roman['I'];
                else if(s[i]=='X' && (s[i+1]=='L' || s[i+1]=='C'))
                    num-=roman['X'];
                else if(s[i]=='C' && (s[i+1]=='D' || s[i+1]=='M'))
                    num-=roman['C'];
                else
                    num+=roman[s[i]];
            }
            else
                num+=roman[s[i]];
        }
        return num;
    }
};
