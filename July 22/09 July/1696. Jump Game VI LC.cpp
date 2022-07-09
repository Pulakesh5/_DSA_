// Recursion won't work. Exponential
// DP won't work because of O(nk) time complexity.
// priority queue works because of O(nlogk) TC

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        
        priority_queue<pair<int,int>> pq;
        
        int ans=0;
        for(int i=n-1;i>=0;i--){
            while(pq.size() && (pq.top().second-i)>k)
                pq.pop();
            
            ans=nums[i]+(pq.size() ? pq.top().first : 0);
            pq.push({ans,i});
        }
        return ans;
    }
};
