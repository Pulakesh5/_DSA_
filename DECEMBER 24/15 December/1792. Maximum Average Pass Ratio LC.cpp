class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto increment = [&](double pass, double total) {
            return (pass+1)/(total+1) - (pass/total);
        };
        double avgPassRatio = 0.0;
        priority_queue<pair<double, array<int,2>>> pq;
        for(auto &c:classes)
        {
            avgPassRatio += (double) c[0]/c[1];
            pq.push({increment(c[0], c[1]), {c[0], c[1]}});
        }
        while(extraStudents--)
        {
            auto [added_profit, c] = pq.top();
            pq.pop();
            avgPassRatio += added_profit;
            pq.push({increment(c[0]+1, c[1]+1), {c[0]+1, c[1]+1}});
        }
        return avgPassRatio/classes.size();
    }
};
