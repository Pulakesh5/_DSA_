/*
    Think greedy
*/


class Solution {
public:
    struct comp{
        template<typename T>
        bool operator() (const T& l, const T& r) const
        {
            if(l[0]==r[0])
                return l[1] > r[1];
            return l[0] < r[0];
        }
    };
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(), points.end(),comp());
       /*
        for(auto arr:points){
            for(auto it:arr)
                cout<<it<<" ";
            cout<<endl;
        }
       */
        int i=0,j=0;
        int arrow=0;
        int start=points[0][0],end=points[0][1];
        while(i<n){
            j=i+1;
            end=points[i][1];
            start=points[i][0];
            while(j<n && (points[j][0] <= end && points[j][1]>=start)){
                end=min(end,points[j][1]);
                start=max(start,points[j][0]);
                j++;
            }
            arrow++;
           // cout<<"i "<<i<<" j "<<j<<" "<<arrow<<endl;
            i=j;
        }
        return arrow;
    }
};
