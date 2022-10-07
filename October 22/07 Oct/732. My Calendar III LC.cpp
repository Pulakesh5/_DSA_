class MyCalendarThree {
public:
    map<int,int> intervals;
    int maxCount=0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        intervals[start]++;
        intervals[end]--;
        int countOfEvents=0;
        for(auto it=intervals.begin();it!=intervals.end();it++)
        {
            countOfEvents+=(it->second);
            maxCount=max(countOfEvents,maxCount);
        }
        return maxCount;
    }
};
