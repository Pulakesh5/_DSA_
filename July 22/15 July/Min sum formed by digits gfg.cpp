class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        priority_queue<int> pq(arr,arr+n);
        long long sum=0,s=0,ten=1;
        while(pq.size()>=2){
            s=pq.top();
            pq.pop();
            s+=pq.top();
            pq.pop();
            sum+=(s*ten);
            ten*=10;
        }

        if(pq.size()>0)
            sum+=(pq.top() * ten);
        return sum;
    }
};
