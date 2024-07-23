
static bool comp(pair<int,int> &a, pair<int,int> &b)
{
    if(a.first!=b.first)
        return a.first<b.first;
    return a.second>b.second;
}
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> freq;
        for(int num:nums)
            freq[num]++;
        vector<pair<int,int>> vp;
        for(auto [num, fr]:freq)
            vp.push_back({fr, num});
        sort(vp.begin(), vp.end(), comp);
        vector<int> sorted;
        for(auto it:vp)
        {
            for(int i=0; i<it.first; i++)
                sorted.push_back(it.second);
        }
        
        return sorted;

    }
};
