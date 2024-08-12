class KthLargest {
public:
    priority_queue<int> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int num:nums)
            pq.push(-1*num);
        while(pq.size()>k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(-1*val);
        if(pq.size()>K)
            pq.pop();
        return -1*pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
