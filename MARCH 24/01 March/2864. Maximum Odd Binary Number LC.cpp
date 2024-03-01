class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int oneCount=0, zeroCount=0;
        for(char ch:s)
        {
            if(ch=='0')
                zeroCount++;
            else
                oneCount++;
        }
        string maxOddBinary = "";
        while(oneCount>1)
        {
            maxOddBinary.push_back('1');
            oneCount--;
        }
        while(zeroCount)
        {
            maxOddBinary.push_back('0');
            zeroCount--;
        }
        maxOddBinary.push_back('1');

        return maxOddBinary;
    }
};
