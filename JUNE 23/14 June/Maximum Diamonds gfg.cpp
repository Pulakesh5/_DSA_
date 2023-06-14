class Solution {
  public:
    long long maxDiamonds(int A[], int N, int K) {
        // code here
        priority_queue<int> pq(A,A+N);
        long long diamonds = 0, top;
        while(pq.size() && K--)
        {
            top = pq.top();
            pq.pop();
            if(top/2)
                pq.push(top/2);
            diamonds+=top;
        }
        return diamonds;
    }
};
