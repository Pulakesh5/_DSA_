class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int operation = 0;
        while(pq.size()>=2 && pq.top()<k)
        {
            long long top1 = pq.top(); pq.pop();
            long long top2 = pq.top(); pq.pop();
            pq.push(min(top1, top2)+top1+top2);
            operation++;
        }
        return operation;
    }
};
