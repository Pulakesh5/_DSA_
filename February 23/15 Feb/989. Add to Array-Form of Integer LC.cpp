class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> num2;
        while(k)
        {
            num2.push_back(k%10);
            k/=10;
        }
        reverse(num2.begin(),num2.end());
        int carry=0, sum=0;
        vector<int> result;
        while(num.size() && num2.size())
        {
            sum=(num.back() + num2.back() + carry);
            result.push_back(sum%10);
            num.pop_back();
            num2.pop_back();
            carry=sum/10;
        }

        while(num.size())
        {
            sum = num.back() + carry;
            result.push_back(sum%10);
            num.pop_back();
            carry = sum/10;
        }
        while(num2.size())
        {
            sum = num2.back() + carry;
            result.push_back(sum%10);
            num2.pop_back();
            carry = sum/10;
        }
        if(carry) result.push_back(carry);
        if(result.size()==0) result={0};
        reverse(result.begin(), result.end());

        return result;
    }
};
