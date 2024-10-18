class Solution {
  public:
    int getSingle(vector<int>& arr) {
        // code here
        int ans = 0;
        for(int num:arr)
            ans = ans^num;
        return ans;
    }
};
