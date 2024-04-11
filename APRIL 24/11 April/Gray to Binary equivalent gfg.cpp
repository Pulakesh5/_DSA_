class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    string binaryToDecimal(int n)
    {
        string binary = "";
        while(n)
        {
            binary.push_back(n%2+'0');
            n/=2;
        }
        reverse(binary.begin(), binary.end());
        return binary;
    }
    int grayToBinary(int n)
    {
        
        // Your code here
        if(n<=1)
            return n;
        
        string gray = binaryToDecimal(n);
        
        int len = gray.size();
        int decimal = 1, prev = 1;
        
        for(int i=1; i<len; i++)
        {
            decimal = decimal*2;
            prev = ((gray[i]-'0')^prev);
            decimal += prev;
        }
        
        return decimal;
    }
};
