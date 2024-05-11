class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<vector<double>> workers;
        for(int i=0; i<quality.size(); i++)
        {
            workers.push_back({(double)(wage[i])/quality[i], (double)(quality[i])});
        }
        sort(workers.begin(), workers.end());
        priority_queue<int> pq;
        double result = DBL_MAX, qsum = 0;
        for(auto worker:workers)
        {
            qsum += (worker[1]);
            pq.push(worker[1]);
            if(pq.size() > k)
            {
                qsum -= pq.top();
                pq.pop();
            }
            if(pq.size()==k)
            {
                result = min(result, qsum*worker[0]);
            }
        }
        return result;
    }
};
