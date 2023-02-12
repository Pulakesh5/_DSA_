class Solution {
public:
    int seatCount;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size();
        vector<vector<int>> adjCity(n+1);
        vector<bool> visited(n+1,false);
        for(auto road:roads)
        {
            adjCity[road[0]].push_back(road[1]);
            adjCity[road[1]].push_back(road[0]);
        }
        seatCount=seats;
        long long FuelCost=0;
        int currentCity=0, distance=0;

        DFS(currentCity, FuelCost, visited, adjCity);
        return FuelCost;
    }

    int DFS(int currentCity, long long &FuelCost, vector<bool> &visited, vector<vector<int>> &adjCity)
    {
        if(visited[currentCity]) return 0;

        
        int cityCount=1;
        visited[currentCity]=true;

        for(int city:adjCity[currentCity])
        {
            if(visited[city]) continue;
            cityCount += DFS(city, FuelCost, visited, adjCity);
        }
        if(currentCity!=0)
        FuelCost += (cityCount+seatCount-1)/seatCount;

        return cityCount;
    }
};
