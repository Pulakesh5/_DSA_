class Solution {
public:
    static bool cmp(int num1, int num2)
    {
        int bits1 = __builtin_popcount(num1);
        int bits2 = __builtin_popcount(num2);
        if(bits1 != bits2)
            return bits1<bits2;
        else
            return num1<num2;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
