class Solution {
public:
    string largestGoodInteger(string num) {
        int digit=-1;
        int len = num.size();
        for(int i=0; i<(len-2); i++)
        {
            if(num[i]==num[i+1] && num[i+1]==num[i+2])
                digit = max(digit,num[i]-'0');
        }
        string goodInteger = "";
        if(digit!=-1)
        {
            goodInteger.push_back('0'+digit);
            goodInteger.push_back('0'+digit);
            goodInteger.push_back('0'+digit);
        }
        return goodInteger;
    }
};
