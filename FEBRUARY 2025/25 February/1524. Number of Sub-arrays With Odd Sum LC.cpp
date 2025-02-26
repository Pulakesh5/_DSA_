class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int N = arr.size();
        int odd = 0, even = 1;
        int totalSum = 0, ans = 0, MOD = 1e9+7;
        for(int num:arr)
        {
            totalSum += num;
            if(totalSum%2)  
            {
                ans = (ans+even)%MOD;
                odd++;
            }
            else
            {
                ans = (ans+odd)%MOD;
                even++;
            }
            
        }
        return ans;
    }
};
