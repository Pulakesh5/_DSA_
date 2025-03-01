class Solution{
public:
    int i=0;
    string decodedString(string s){
        // code here
        int count=0;
        string sub="";
        while(s[i]>='0' && s[i]<='9')
        {
            count=(count*10+s[i]-'0');
            i++;
        }
        i++; // for [
        while(s[i]!=']')
        {
            if(s[i]>='a' && s[i]<='z')
            {
                sub+=s[i];
                i++;
            }
            else
                sub+=decodedString(s);
        }
        i++;
        string temp="";
        while(count--)
            temp+=sub;
        
        while(i<s.size() && s[i]>='0' && s[i]<='9') temp+=decodedString(s);
        
        return temp;
        
    }
};
