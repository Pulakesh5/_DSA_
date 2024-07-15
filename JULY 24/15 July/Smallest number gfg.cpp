class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if(s>d*9)
            return "-1";
        vector<int> digits(d);
        s--;
        digits[0] = 1;
        int digit, pos = d-1;
        while(pos>=0 && s)
        {
            digit = min(9-digits[pos], s);
            digits[pos] += digit;
            s -= digit;
            pos--;
        }

        string numString = "";
        for(int i=0; i<d; i++)
            numString.push_back(digits[i]+'0');
        return numString;
    }
};
