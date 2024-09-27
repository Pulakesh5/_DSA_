class MyCalendarTwo {
public:
    vector<pair<int, int>> singleBooked, doubleBooked; // [end] -> start
    // map<int, int> bookings;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto booking:doubleBooked)
        {
            if(start<booking.second && end>booking.first)
                return false;
        }

        for(auto booking:singleBooked)
        {
            if(start<booking.second && end>booking.first)
                doubleBooked.push_back({max(booking.first, start), min(booking.second, end)});
        }
        singleBooked.push_back({start, end});
        return true;
    }

};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
