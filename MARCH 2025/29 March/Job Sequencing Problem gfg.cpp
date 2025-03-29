class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<pair<int,int>> vp(n);
        int maxDays = -1;
        for(int i=0; i<n; i++) {
            vp[i] = {profit[i], deadline[i]};
            maxDays = max(maxDays, deadline[i]);
        }
        
        sort(vp.begin(), vp.end(), [](pair<int,int> a, pair<int,int> b){
            return a.first>b.first;
        });
        
        int current = vp[n-1].first-1;
        int jobsDone = 0, totalProfit = 0;
        vector<int> parent(maxDays+5);
        for(int i=0; i<=maxDays; i++)
            parent[i] = i;
            
        function<int(int)> find = [&] (int day) {
            if(parent[day] == day)
                return day;
            return parent[day] = find(parent[day]);
        };
        
        for(int i=0; i<n; i++) {
            int available = find(vp[i].second);
            
            if(available>0)
            {
                jobsDone++;
                totalProfit+=vp[i].first;
                parent[available] = find(available-1);
            }
        }
        
        return {jobsDone, totalProfit};
    }
};
