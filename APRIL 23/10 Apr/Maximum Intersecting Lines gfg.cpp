class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        map<int,int> points;
        for(auto line:lines)
        {
            points[line[0]]++;
            points[line[1]+1]--;
        }
        int intersectingLine=0, maxIntersect=0;
        for(auto point:points)
        {
            // cout<<point.first<<" "<<point.second<<endl;
            intersectingLine+=point.second;
            // cout<<intersectingLine<<endl;
            maxIntersect=max(maxIntersect,intersectingLine);
        }
        return maxIntersect;
    }
};
