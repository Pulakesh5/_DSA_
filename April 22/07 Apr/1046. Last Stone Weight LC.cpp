class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(),stones.end());
        q.push(0);
        while(q.size()>1){
            int top1=q.top();
            q.pop();
            int top2=q.top();
            q.pop();
            if(top1!=top2)
                q.push(top1-top2);
        }
        if(q.size())
            return q.top();
        return 0;
        
    }
};
