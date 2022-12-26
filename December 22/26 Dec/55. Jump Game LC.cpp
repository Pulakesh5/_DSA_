class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> reachable(n,0);
        reachable[0]=true;

        for(int i=0;i<n;i++)
        {
            if(reachable[i])
            {
                for(int j=i+1;j<=(i+nums[i]) && j<n;j++)
                {
                    //cout<<j<<" ";
                    reachable[j]=true;
                    if(j==n-1) return true;
                }
                //cout<<endl;
            }
        }
        return reachable[n-1];
    }
};
