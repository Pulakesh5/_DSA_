    int minimumTime(int N,int cur,vector<int> &pos,vector<int> &time){
        long long minTime=INT_MAX;
        long long boardingTime;
        
        for(int i=0;i<N;i++)
        {
            boardingTime = 1ll*abs(cur-pos[i])*time[i];
            minTime = min(minTime, boardingTime);
        }
        return minTime;
    }
