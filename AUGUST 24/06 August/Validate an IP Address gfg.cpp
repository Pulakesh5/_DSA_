class Solution {
    public:
    int isValid(string s) {
        // code here
        int len = s.size();
        if(len>15)
            return 0;
            
        int dec=-1, prev=0, index=0;
        for(int k=0; k<4; k++)
        {
            dec =-1;
            if(k<4 && index==len)
                return 0;
            while(index<len && s[index]!='.' && dec<256)
            {
                if(dec==0 && s[index]=='0')
                    return 0;
                if(dec==-1)
                    dec = 0;
                if(s[index]<'0' || s[index]>'9' || (dec==0 && s[index]=='0' && (index+1)<len && (s[index+1]>='1' && s[index+1]<='9')))
                    return 0;
                
                dec = dec*10 + (s[index]-'0');
                
                // cout<<index<<" "<<dec<<endl;
                index++;
            }
            if(dec>=256 || prev==-1)
            {
                // cout<<prev<<" "<<dec<<" "<<index<<endl;
                return 0;
            }
            if(index<len && s[index]=='.')
                index++;
            prev = dec;
        }
        return index==len && s[index-1]!='.'; 
    }
};
