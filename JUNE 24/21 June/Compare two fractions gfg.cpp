class Solution {
  public:
    string compareFrac(string str) {
        // Code here
        vector<float> number(4);
        int i=0;
        int len = str.size();
        while(str[i]==' ' && i<len)
            i++;
        // processing a
        while(i<len && str[i]!='/')
            number[0] = (number[0]*10+str[i++]-'0');
        i++;
        // processing b
        while(i<len && str[i]!=',')
            number[1] = (number[1]*10+str[i++]-'0');
        i++;
        //skipping spaces
        while(str[i]==' ' && i<len)
            i++;
        //processing c
        while(i<len && str[i]!='/')
            number[2] = (number[2]*10+str[i++]-'0');
        i++;
        // processing d
        while(i<len && str[i]!=' ')
            number[3] = (number[3]*10+str[i++]-'0');
        
        float a_b = number[0]/number[1];
        float c_d = number[2]/number[3];
        
        // cout<<number[0]<<" "<<number[1]<<" "<<number[2]<<" "<<number[3]<<endl;
        // cout<<a_b<<" "<<c_d<<endl;
        
        string msg = "";
        if(a_b == c_d)
            return "equal";
        else if(a_b > c_d)
        {
            msg += to_string((int)number[0]);
            msg.push_back('/');
            msg += to_string((int)number[1]);
        }
        else{
            msg += to_string((int)number[2]);
            msg.push_back('/');
            msg += to_string((int)number[3]);
        }
        return msg;
    }
};
