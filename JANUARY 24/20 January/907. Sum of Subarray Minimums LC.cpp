class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int len = arr.size();
        vector<long long> stk, sums(len,0);
        long long j, result=0, MOD=1e9+7;
        for(int i=0; i<len; i++)
        {
            while(!stk.empty() && arr[stk.back()]>arr[i])
                stk.pop_back();
            j = (!stk.empty()) ? (stk.back()) : -1;
            sums[i] = ((j>-1 ? sums[j]:0) + 1ll*(i-j)*arr[i]) % MOD;
            stk.push_back(i);
        }
        for(int i=0; i<len; i++)
            result = (result + sums[i]) %MOD;
        return result;
    }
};
