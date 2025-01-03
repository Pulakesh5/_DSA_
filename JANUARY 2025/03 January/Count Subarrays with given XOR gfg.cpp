class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        map<long long, long long> prefixXORCount;
        prefixXORCount[0] = 1;
        
        size_t N = arr.size();
        long long prefixXOR = 0, subarrayCount = 0;
        for(int i=0; i<N; i++)
        {
            prefixXOR ^= arr[i];
            subarrayCount += prefixXORCount[prefixXOR^k];
            prefixXORCount[prefixXOR]++;
        }
        
        return subarrayCount;
    }
};
