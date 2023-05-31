class UndergroundSystem {
public:
    map<int,pair<string,int>> passengerCheckIn;
    map<pair<string, string>, pair<double, int>> AverageTime; 
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        passengerCheckIn[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string boardingStation = passengerCheckIn[id].first;
        double totalTime = AverageTime[{boardingStation, stationName}].first;
        double time =  t - passengerCheckIn[id].second;
        int count = AverageTime[{boardingStation, stationName}].second;
        AverageTime[{boardingStation, stationName}] = {totalTime+time, count+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        int count = AverageTime[{startStation, endStation}].second;
        double totalTime = AverageTime[{startStation, endStation}].first;
        return totalTime/count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
