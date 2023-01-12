    int minimizeSum(int N, vector<int> arr) {
        // code here
        priority_queue<int,vector<int>, greater<int>> pq(arr.begin(), arr.end());
        int sum=0;
        while(pq.size()>1)
        {
            int num1=pq.top();
            pq.pop();
            int num2=pq.top();
            pq.pop();
            sum+=(num1+num2);
            pq.push(num1+num2);
        }
        return sum;
    }
