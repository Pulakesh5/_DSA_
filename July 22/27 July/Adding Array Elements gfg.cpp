class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>> pq(arr,arr+n);
        int operation=0,sum=0;
        while(pq.size()>=2 && pq.top()<k){
            sum=pq.top();
            pq.pop();
            sum+=pq.top();
            pq.pop();
            pq.push(sum);
            operation++;
        }
        return pq.top()>= k ? operation : -1;
        
    }
};
