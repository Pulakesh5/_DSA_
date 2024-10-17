class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        while(num) {
            digits.push_back(num%10);
            num = num/10;
        }
        reverse(digits.begin(), digits.end());

        for(int i=0; i<(digits.size()-1); i++) {
            int k=i, digit=digits[i];
            for(int j=digits.size()-1; j>i; j--)
            {
                if(digit<digits[j])
                {
                    digit = digits[j];
                    k = j;
                }
            }
            if(k>i)
            {
                swap(digits[i], digits[k]);
                break;
            }
        }
        int maximumNumber = 0;
        for(int i=0; i<digits.size(); i++) {
            maximumNumber = maximumNumber*10 + digits[i];
        }
        return maximumNumber;
    }
};
