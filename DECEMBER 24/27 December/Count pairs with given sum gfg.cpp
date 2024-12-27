class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        map<int,int> freq;
        for(int num:arr)
            freq[num]++;
        int count = 0;
        for(auto it:freq)
        {
            int num = it.first, f = it.second;
            if(target != 2*num)
                count += (f*freq[target-num]);
            else
                count += (f*(f-1));
        }
        return count/2;
    }
};
