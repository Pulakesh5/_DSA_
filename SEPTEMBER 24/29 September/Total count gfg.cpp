class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        // code here
        int total_count = 0;
        for(int num:arr)
            total_count += (num+k-1)/k;
        
        return total_count;
    }
};
