class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());

        while(k && pq.top()!=1)
        {
            int mx=pq.top();
            pq.pop();
            pq.push(mx-(mx/2));
            k--;
        }
        int ans=0;
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};
