class Solution {
public:
    string addBinary(string a, string b) {
        string sum="";
        int bit_a,bit_b,bit_sum,carry=0;
        while(a.size() && b.size())
        {
            bit_a=a.back();
            bit_b=b.back();
            bit_sum=(bit_a-'0'+bit_b-'0'+carry);
            sum.push_back((char)('0'+bit_sum%2));
            carry=bit_sum/2;
            a.pop_back();
            b.pop_back();
        }

        while(a.size())
        {
            bit_a=a.back();
            bit_sum=bit_a-'0'+carry;
            sum.push_back((char)('0'+bit_sum%2));
            carry=bit_sum/2;
            a.pop_back();
        }
        while(b.size())
        {
            bit_b=b.back();
            bit_sum=bit_b-'0'+carry;
            sum.push_back((char)('0'+bit_sum%2));
            carry=bit_sum/2;
            b.pop_back();
        }
        if(carry)
            sum.push_back((char)('0'+carry));

        reverse(sum.begin(), sum.end());
        return sum;

    }
};
