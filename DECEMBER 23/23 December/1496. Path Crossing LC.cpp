class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> visitedPoints;
        int x=0, y=0;
        visitedPoints.insert({0,0});
        for(char direction:path)
        {
            if(direction=='N')
                y++;
            else if(direction=='S')
                y--;
            else if(direction=='E')
                x++;
            else
                x--;
            if(visitedPoints.find({x,y})!=visitedPoints.end())
                return true;
            visitedPoints.insert({x,y});
        }
        return false;
    }
};
