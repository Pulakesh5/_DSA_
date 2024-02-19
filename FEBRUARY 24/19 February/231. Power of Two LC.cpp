class Solution {
public:
    bool isPowerOfTwo(int n) {
        cout<<(n&(n-1))<<endl;
        return !(n&(n-1));
    }
};
