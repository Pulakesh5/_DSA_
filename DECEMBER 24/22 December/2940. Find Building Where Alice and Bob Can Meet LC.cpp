class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        int qs = q.size();
        vector<int> ans(qs), rem_idx;
        // processing obvious answers and keeping the remaining index of queries
        for(int i=0; i<qs; i++)
        {
            sort(q[i].begin(), q[i].end());
            if(q[i][0]==q[i][1] || h[q[i][0]] < h[q[i][1]])
                ans[i] = q[i][1];
            else
                rem_idx.push_back(i);
        }
        // sorting remaining index of queries according to descending order
        sort(rem_idx.begin(), rem_idx.end(), [&](int i, int j) {return q[i][1] > q[j][1];});
        int j = h.size()-1;
        vector<int> mon_stack;
        for(int index:rem_idx)
        {
            int a = q[index][0], b = q[index][1];
            while(j>b)
            {
                while(!mon_stack.empty() && h[mon_stack.back()]<=h[j])
                    mon_stack.pop_back();
                mon_stack.push_back(j--);
            }
            auto it = upper_bound(mon_stack.rbegin(), mon_stack.rend(), a, [&](int i, int j){
                return h[i] < h[j];
            });
            ans[index] = (it==rend(mon_stack)) ? -1:*it;
        }
        return ans;
    }
};
