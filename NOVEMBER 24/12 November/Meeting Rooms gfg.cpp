class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        sort(arr.begin(), arr.end());
        int prevEnd = -1;
        for(vector<int> interval:arr)
        {
            if(interval[0]<prevEnd)
                return false;
            prevEnd = interval[1];
        }
        return true;
    }
};
