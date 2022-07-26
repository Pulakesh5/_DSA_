class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;//num->length of consecutive sequence
        int n=nums.size();
        int maxLength=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]=1;
        }

        for(auto &pr:mp)
        {
            if(mp.find(pr.first-1)!=mp.end())
                mp[pr.first]+=mp[pr.first-1];
            maxLength=max(maxLength,mp[pr.first]);
        }
        return maxLength;
    }
};
