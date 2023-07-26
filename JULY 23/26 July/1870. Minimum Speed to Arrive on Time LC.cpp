class Solution {
public:
    double timeRequired(vector<int> &dist, int speed)
    {
        double time = 0, t;
        // cout<<speed<<" : "<<endl;
        int len = dist.size();
        for(int i=0; i<len; i++){
            // if(time != floor(time))
            //     time = floor(time) + 1.00;
            // cout<<dist[i]<<" "<<time<<endl;
            t = (1.0*dist[i])/speed;
            if(i!=(len-1))
                time += ceil(t);
            else
                time += t;
            // cout<<dist[i]<<" "<<t<<" "<<time<<endl;
        }
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int _hour = ceil(hour);
        int len = dist.size();
        if(_hour<len)
            return -1;
        int minSpeed = 1, maxSpeed = 1e7, reqSpeed;//*max_element(dist.begin(), dist.end());
        int speed;
        double time;

        while(minSpeed<=maxSpeed)
        {
            speed = minSpeed+(maxSpeed - minSpeed)/2;
            time = timeRequired(dist, speed);
            if(time<=hour)
            {
                reqSpeed = speed;
                maxSpeed = speed - 1;
            }
            else
                minSpeed = speed + 1;
        }
        return reqSpeed;
    }
};

