class Solution {
public:
    int maximum69Number (int num) {
        //cout<<num<<endl;
        vector<int> digits;
        while(num)
        {
            digits.push_back(num%10);
            //cout<<num%10<<" ";
            num/=10;
        }
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits[i]==6)
            {
                digits[i]=9;
                break;
            }
        }
        num=0;
        for(int i=digits.size()-1;i>=0;i--)
        {
            num=(num*10+digits[i]);
        }
        return num;
    }
};
