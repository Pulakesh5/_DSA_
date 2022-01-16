//Think greedily, don't miss edge cases
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int distance=0,n=seats.size();
        vector<int> seat;
        for(int i=0;i<n;i++)
            if(seats[i]) seat.push_back(i);
        for(int i=1;i<seat.size();i++)
            distance=max(distance, (seat[i]+seat[i-1])/2 - seat[i-1]);
        distance=max({distance, n-1-seat[seat.size()-1], seat[0]});
        return distance;
    }
};
