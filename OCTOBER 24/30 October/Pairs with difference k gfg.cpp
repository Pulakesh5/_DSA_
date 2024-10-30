class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        map<int,int> freq;
        for(int num:arr)
            freq[num]++;
        int countPairs = 0;
        for(auto itr:freq)
        {
            int num = itr.first, f=itr.second;
            if(freq.find(num+k)!=freq.end())
                countPairs += (freq[num]*freq[num+k]);
        }
        return countPairs;
    }
};
