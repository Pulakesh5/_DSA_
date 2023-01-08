class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=1;
        int n=points.size();

        for(int i=0;i<(n-1);i++)
        {
            map<double,int> slopeCount;
            for(int j=i+1;j<n;j++)
            {
                double slope=(double)(points[j][1]-points[i][1])/(double)(points[j][0]-points[i][0]);
                if((points[j][1]-points[i][1])<0 && (points[j][0]-points[i][0])==0)
                    slopeCount[abs(slope)]++;
                else
                    slopeCount[slope]++;
            }
            int count=0;
            for(auto it:slopeCount)
                count=max(count,it.second+1);
            ans=max(ans,count);
        }
        return ans;
    }
};
