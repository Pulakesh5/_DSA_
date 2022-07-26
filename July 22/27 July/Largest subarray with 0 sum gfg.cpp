class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        map<int,int> mp; // sum,first occurence position
        long long sum=0;
        int ans=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(mp.find(sum)!=mp.end())
            {
                ans=max(ans,i-mp[sum]);
            }
            else
                mp[sum]=i;
        }
        return ans;
    }
};
