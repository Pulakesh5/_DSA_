class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double eps = 1e-6;
        double lb=0, ub=0;
        for(vector<int> square:squares) {
            ub = max(ub,(double)(square[1]+square[2]));
        }
        double separatorLine=0.0, line=0.0;
        while(ub-lb>eps) {
            line = (ub+lb)/2;
            double lowerHalf = 0.0, upperHalf = 0.0;
            double x, y, l;
            for(vector<int> &square:squares) {
                x = square[0];
                y = square[1];
                l = square[2];
                lowerHalf += max((min(line,y+l)-y)*l,0.0);
                upperHalf += max((y+l-max(line,y))*l,0.0);
            }
            // cout<<lb<<" "<<ub<<" | "<<line<<" : "<<lowerHalf<<" "<<upperHalf<<endl;
            if(lowerHalf==upperHalf || lowerHalf-upperHalf >= eps) {
                ub = line;
                separatorLine = line;
            } else {
                lb = line;
            }
        }
        return separatorLine;
    }
};
