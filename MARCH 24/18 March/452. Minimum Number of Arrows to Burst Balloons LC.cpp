class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        int arrow = 0;
        
        long long xleft = points[0][0], xright = points[0][1];

        for(int i=1; i<n; i++)
        {
            if(points[i][0]>xright)
            {
                arrow++;
                xleft = points[i][0];
                xright = points[i][1];
            }
            else
            {
                xleft = max(xleft, 1ll*points[i][0]);
                xright = min(xright, 1ll*points[i][1]);
            }
        }
        arrow++;
        return arrow;
    }
};
