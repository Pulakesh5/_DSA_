class Solution {
public:
    bool validateCoupon(string &code) {
        if(code.size()==0)
            return false;
        for(char ch:code) {
            if(!(isalnum(ch) || ch=='_'))
                return false;
        }
        return true;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<int,string>> validCouponPairs;
        int N = code.size();
        set<string> validBusiness = {"electronics", "grocery", "pharmacy", "restaurant"};
        map<string,int> businessLineCode;
        businessLineCode["electronics"] = 0;
        businessLineCode["grocery"] = 1;
        businessLineCode["pharmacy"] = 2;
        businessLineCode["restaurant"] = 3;

        for(int i=0; i<N; i++) {
            if(validateCoupon(code[i]) && validBusiness.find(businessLine[i])!=validBusiness.end() && isActive[i])
                validCouponPairs.push_back({businessLineCode[businessLine[i]],code[i]});
        }
        sort(validCouponPairs.begin(), validCouponPairs.end());
        vector<string> validCoupons;
        for(pair<int, string> &couponPair:validCouponPairs) {
            validCoupons.push_back(couponPair.second);
        }
        return validCoupons;
    }
};
