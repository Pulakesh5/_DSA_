class Solution {
  public:
    int countgroup(vector<int>& arr) {
        // Complete the function
        int totalXOR = 0;
        for(int num:arr)
            totalXOR = totalXOR^num;
        if(totalXOR != 0)
            return 0;
        long long MOD = 1e9+7, count = 1;
        int N = arr.size()-1;
        while(N--)
            count = (count*2)%MOD;
        return count-1;
        
    }
};
