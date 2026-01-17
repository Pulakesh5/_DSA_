class Solution {
public:
    struct boundary{
        int X, isStart;
        int startY, endY;
    };
    bool isPossible(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight, int side) {
        vector<boundary> boundaries;
        int N = bottomLeft.size();
        int startX, endX, startY, endY;
        for(int i=0; i<N; i++) {
            startX = bottomLeft[i][0];
            startY = bottomLeft[i][1];
            endX = topRight[i][0];
            endY = topRight[i][1];

            if(startX+side>endX || startY+side>endY)    
                continue; // not possible to find overlapping area with sidelength of side
            int validEndX = endX-side, validEndY = endY-side;
            boundaries.push_back({startX, 1, startY, validEndY});
            boundaries.push_back({validEndX, -1, startY, validEndY});
        }
        
        sort(boundaries.begin(), boundaries.end(), [](auto &a, auto &b) {
            if(a.X==b.X) return a.isStart > b.isStart;
            return a.X<b.X;
        });

        set<pair<int,int>> yPoints;
        for(auto &boundary:boundaries) {
            if(boundary.isStart==1) {
                auto it = yPoints.lower_bound({boundary.startY, 0});
                if(it!=yPoints.end() && it->first<=boundary.endY) // if the next square has overlapping from end
                    return true;
                if(it != yPoints.begin()) {
                    --it;
                    if(it->second>=boundary.startY)
                        return true;
                }
                yPoints.insert({boundary.startY, boundary.endY});
            } else 
                yPoints.erase({boundary.startY, boundary.endY});
        }
        return false;
    }
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int low = 1, high = 1e7;
        long long ans = 0, side;
        while(low<=high) {
            side = (low+high)/2;
            if(isPossible(bottomLeft, topRight, side)) {
                ans = side;
                low = side+1;
            } else {
                high = side-1;
            }
        }
        return ans*ans;
    }
};
