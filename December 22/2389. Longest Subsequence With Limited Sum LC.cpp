class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int m=queries.size();

        vector<int> pre(n), ans(m);
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        int k=0;
        for(int q:queries)
        {
            int pos=lower_bound(pre.begin(), pre.end(), q)-pre.begin();
            if(pos<n)
            {
                if(pre[pos]==q) ans[k++]=pos+1;
                else ans[k++]=pos;
            }
            else    ans[k++]=pos;
        }

        return ans;
    }
};
