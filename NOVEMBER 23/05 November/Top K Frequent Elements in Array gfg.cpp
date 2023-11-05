class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        priority_queue<pii> pq;
        map<int, int> freq;
        for(int num:nums)
            freq[num]++;
        for(auto it:freq)
            pq.push({it.second, it.first});
        vector<int> TopKNums;
        while(k--)
        {
            TopKNums.push_back(pq.top().second);
            pq.pop();
        }
        return TopKNums;
    }
};
