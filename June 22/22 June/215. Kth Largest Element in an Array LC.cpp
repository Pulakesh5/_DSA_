class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size(), frnt;
        priority_queue<int> q;
        for(int i=0;i<n;i++){
            q.push(-1*nums[i]);
            if(q.size()>k)
                q.pop();
        }
        return -1*q.top();
    }
};
