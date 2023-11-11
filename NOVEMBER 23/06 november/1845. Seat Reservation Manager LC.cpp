class SeatManager {
public:
    SeatManager(int n) {
        for(int i=1; i<=n; i++)
            seats.insert(i);
    }
    
    int reserve() {
        auto it = seats.begin();
        int seat = *it;
        seats.erase(it);
        return seat;
    }
    
    void unreserve(int seatNumber) {
        seats.insert(seatNumber);
    }
private:
    set<int> seats;
};
