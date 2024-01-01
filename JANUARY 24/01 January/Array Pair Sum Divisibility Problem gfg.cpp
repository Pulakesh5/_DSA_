class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        vector<int> rem(k,0);
        int len=nums.size();
        for(int i=0; i<len; i++)
        {
            rem[nums[i]%k]++;
        }
        if(rem[0]%2==1 || ((k%2==0) && (rem[k/2]%2==1)))
            return false;
        for(int i=1; i<=(k/2); i++)
        {
            if(rem[i]!=rem[k-i])
                return false;
        }
        return true;
    }
};
