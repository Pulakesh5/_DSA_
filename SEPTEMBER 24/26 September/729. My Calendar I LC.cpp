class MyCalendar {
public:
    map<int, int> bookings;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = bookings.upper_bound(start);
        if(it!=bookings.end() && (*it).second<end)
            return false;
        bookings.insert({end, start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
