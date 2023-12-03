class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int distance = 0;
        int prevX=points[0][0], prevY=points[0][1];
        int n=points.size(), dist1, dist2;
        for(int i=1; i<n; i++)
        {
            dist1 = abs(prevX-points[i][0]);
            dist2 = abs(prevY-points[i][1]);
            if(dist1==dist2)
                distance+=dist1;
            else
                distance+=max(dist1, dist2);
            prevX = points[i][0];
            prevY = points[i][1];
        }
        return distance;
    }
};
