class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]>b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrow=0;
        sort(points.begin(), points.end(), cmp);
        int n=points.size();
        long long xl=points[0][0],xr=points[0][1];
        
        for(int i=1;i<n;i++)
        {
            if(points[i][0]>xr)
            {
                arrow++;
                xl=points[i][0];
                xr=points[i][1];
            }
            else
            {
                xl=max(xl,1ll*points[i][0]);
                xr=min(xr,1ll*points[i][1]);
            }
        }
        arrow++;

        return arrow;
    }
};
