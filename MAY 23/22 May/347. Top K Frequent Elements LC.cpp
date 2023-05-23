class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b)
    {
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<pair<int,int>> v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto it:mp)
            v.push_back(it);
        sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        for(int i=0;i<k;i++)
            ans.push_back(v[i].first);
        return ans;
    }
};
