
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        
        int targetArrival = times[targetFriend][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        sort(times.begin(), times.end());
        priority_queue<int, vector<int>, greater<int>> seats;
        
        int arrival, departure, available;
        int used = 0;

        for(vector<int> period:times) {
            arrival = period[0];
            departure = period[1];

            while(!pq.empty() && pq.top()[0] <= arrival) {
                seats.push(pq.top()[1]);
                pq.pop();
            }

            if(seats.size()!=0) {
                available = seats.top();
                seats.pop();
            } else {
                available = used;
                used++;
            }

            pq.push({departure, available});
            if(targetArrival == arrival)
                return available;
        }

        return 0;
    }
};
