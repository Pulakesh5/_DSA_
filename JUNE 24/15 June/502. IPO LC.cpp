class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int len = profits.size();
        vector<pair<int,int>> pr(len);
        
        for(int i=0; i<len; i++)
            pr[i] = {capital[i], -1*profits[i]};
        sort(pr.begin(), pr.end());

        priority_queue<int> pq;
        int last, initialCapital = w;
        for(last=0; last<len && pr[last].first<=initialCapital; last++)
        {
            // cout<<"pushing "<<(-1*pr[last].second)<<endl;
            pq.push(-1*pr[last].second);
        }

        while(k>0 && !pq.empty())
        {
            int projectProfit = pq.top();
            pq.pop();
            
            // cout<<"capital, profit :"<<initialCapital<<" "<<projectProfit<<endl;
            initialCapital += projectProfit;
            while(last<len && pr[last].first<=initialCapital)
            {
                pq.push(-1*pr[last].second);
                // cout<<"pushing "<<(-1*pr[last].second)<<endl;
                last++;
            }
            k--;
        }
        return initialCapital;
    }
};
