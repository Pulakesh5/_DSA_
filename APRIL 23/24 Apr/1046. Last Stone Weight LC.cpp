class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        int top, nextTop;
        while(pq.size()>1)
        {
            top = pq.top();
            pq.pop();
            if(top==pq.top())
                pq.pop();
            else 
                {
                    nextTop = pq.top();
                    pq.pop();
                    pq.push(top-nextTop);
                }
        }
        if(pq.size()==0) return 0;
        return pq.top();
    }
};
