class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        priority_queue<pair<int,pair<int,int>>> qa,qb;
        for(auto &v:costs){
            if(v[0]<=v[1])
                qa.push({-1*abs(v[0]-v[1]),{v[0],v[1]}});
            else
                qb.push({-1*abs(v[0]-v[1]),{v[0],v[1]}});
        }
        while(qa.size()>(n/2)){
            auto it=qa.top();
            qb.push(it);
            qa.pop();
        }
        while(qb.size()>(n/2)){
            auto it=qb.top();
            qa.push(it);
            qb.pop();
        }
        int ans=0;
        while(!qa.empty()){
            auto it=qa.top();
            ans+=it.second.first;
            qa.pop();
        }
        while(!qb.empty()){
            auto it=qb.top();
            ans+=it.second.second;
            qb.pop();
        }
        return ans;
    }
};
