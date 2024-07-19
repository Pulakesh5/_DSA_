class Solution {
  public:
     vector<int> constructLowerArray(vector<int> &nums) {
        int n=nums.size();
        vector<int> stack;
        vector<int> cnt(n,0);
        stack.push_back(nums[n-1]);
        cnt[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>stack.back())
            {
                stack.push_back(nums[i]);
                cnt[i]=stack.size()-1;
            }
            else
            {
                int ind=lower_bound(stack.begin(),stack.end(),nums[i])-stack.begin();
                stack.insert(stack.begin()+ind,nums[i]);
                cnt[i]=ind;
            }
        }
        return cnt;
    }
};
