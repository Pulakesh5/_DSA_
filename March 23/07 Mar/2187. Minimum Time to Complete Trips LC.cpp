xclass Solution {
public:
    long long check(vector<int> &times, long long totalTime)
    {
        long long tripCount=0;

        for(auto time:times)
            tripCount+=(totalTime/time);
        
        //cout<<totalTime<<" : "<<tripCount<<endl;

        return tripCount;
    }
    long long minimumTime(vector<int>& times, int totalTrips) {

        long long l=0,r= 1e14;//*max_element(times.begin(), times.end());
        long long minTime=1e18, totalTime;
        
        while(l<=r)
        {
            totalTime=(l+r)/2;
            if(check(times, totalTime)>=totalTrips)
            {
                r=totalTime-1;
                minTime=min(minTime,totalTime);
            }
            else
                l=totalTime+1;
        }
        
        return minTime;
    }
};
