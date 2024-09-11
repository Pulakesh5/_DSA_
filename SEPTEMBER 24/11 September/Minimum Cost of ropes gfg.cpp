class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here 
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int num:arr)
            pq.push(num);
        long long cost = 0, sum;
        while(pq.size()>1)
        {
            long long top1 = pq.top();
            pq.pop();
            long long top2 = pq.top();
            pq.pop();
            // cout<<top1<<", "<<top2<<endl;
            sum = (top1+top2);
            cost += sum;
            pq.push(sum);
        }
        return cost;
    }
};
