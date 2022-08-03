class MyCalendar {
public:
    map<int,int> st;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        auto it=st.upper_bound(start);
        if(it!=st.end() && (*it).second<end) return false;
        st.insert({end,start});
        return true;
        
    }
};
