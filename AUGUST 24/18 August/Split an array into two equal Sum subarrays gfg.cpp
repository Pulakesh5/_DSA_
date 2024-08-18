class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int total = 0;
        for(int num:arr)
            total+=num;
        int sum = 0;
        for(int num:arr)
        {
            sum+=num;
            if(2*sum==total)
                return true;
        }
        return false;
    }
};
