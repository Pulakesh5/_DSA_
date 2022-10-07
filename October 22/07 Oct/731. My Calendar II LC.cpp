class MyCalendarTwo {
public:
    map<int,int> intervals;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        intervals[start]++;
        intervals[end]--;
        int count=0;
        int booking=0;
        for(auto it=intervals.begin(); it!=intervals.end();it++)
        {
            //cout<<it->first<<' '<<it->second<<endl;
            count+=(it->second);
            if(count==3){
                intervals[start]--;
                intervals[end]++;
                return false;
            }
        }
        return true;
    }
};
