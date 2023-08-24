class Solution{
    private:
    void parse_string_in_vec(const std::string& str, std::vector<int>& vec) {
        int leading_zero_mode = true;

        for (const auto& c : str) {
            if (c != '-') {
                if (leading_zero_mode && c != '0') {
                    leading_zero_mode = false;
                    vec.push_back(static_cast<int>(c - '0'));
                } else if (!leading_zero_mode) {
                    vec.push_back(static_cast<int>(c - '0'));
                }
            }
        }
    }

    public:
    /*You are required to complete below function */
    // string stringMul(string str, int mul)
    // {
    //     string ans = "";
    //     int digit, carry = 0;
    //     reverse(str.begin(), str.end());
    //     for(char ch:str)
    //     {
    //         digit = ch-'0';
    //         digit*=mul;
    //         digit+=carry;
    //         ans.push_back(digit%10 + '0');
    //         carry = digit/10;
    //     }
    //     if(carry)
    //         ans.push_back(carry+'0');
    //     reverse(ans.begin(), ans.end());
    //     return ans;
    // }
    // string stringAdd(string s1, string s2)
    // {
    //     int i1 = s1.size()-1, i2=s2.size()-1;
    //     int carry=0, digit;
    //     string ans = "";
    //     while(i1>=0 && i2>=0)
    //     {
    //         digit = (s1[i1] - '0' + s2[i2] -'0' + carry);
    //         ans.push_back(digit%10+'0');
    //         carry=digit/10;
    //         i1--;
    //         i2--;
    //     }
    //     while(i2>=0)
    //     {
    //         digit = (s2[i2] -'0' + carry);
    //         ans.push_back(digit%10+'0');
    //         carry=digit/10;
    //         i2--;
    //     }
    //     if(carry)
    //         ans.push_back(carry+'0');
    //     reverse(ans.begin(), ans.end());
    //     return ans;
    // }
    string multiplyStrings(string s1, string s2) {
       //Your code here
        if (s1 == "0" || s2 == "0") return "0"; // Special case when one of them is zero

        int sign1 = (s1[0] == '-') ? -1 : 1;
        int sign2 = (s2[0] == '-') ? -1 : 1;
        int result_sign = sign1 * sign2;

        std::vector<int> v1, v2;
        parse_string_in_vec(s1, v1);
        parse_string_in_vec(s2, v2);

        std::reverse(v1.begin(), v1.end());
        std::reverse(v2.begin(), v2.end());

        std::vector<int> result_vec(v1.size() + v2.size(), 0);

        for (int i = 0; i < v1.size(); ++i) {
            for (int j = 0; j < v2.size(); ++j) {
                int res_idx = i + j;
                int res = result_vec[res_idx] + v1[i] * v2[j];

                result_vec[res_idx] = res % 10;
                result_vec[res_idx + 1] += res / 10;
            }
        }

        // Remove leading zeroes from result_vec
        while (result_vec.size() > 1 && result_vec.back() == 0) {
            result_vec.pop_back();
        }

        std::string result;
        if (result_sign == -1) {
            result += '-';
        }

        for (int i = result_vec.size() - 1; i >= 0; --i) {
            result += std::to_string(result_vec[i]);
        }

        return result;
    }

};
