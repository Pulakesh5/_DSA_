class Solution {
public:
    static bool comp(pair<int,int> &a, pair<int,int> &b) {
        if(a.first!=b.first)
            return a.first<b.first;
        return a.second>b.second;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int N = rectangles.size();
        vector<pair<int,int>> verticalBoundaries, horizontalBoundaries;
        for(auto rectangle:rectangles) {
            verticalBoundaries.emplace_back(rectangle[1], rectangle[3]);
            horizontalBoundaries.emplace_back(rectangle[0], rectangle[2]);
        }
        
        sort(verticalBoundaries.begin(), verticalBoundaries.end(), comp);
        sort(horizontalBoundaries.begin(), horizontalBoundaries.end(), comp);
        
        // processing vertical bounderies
        int cut = 0;
        int verticalLast = verticalBoundaries[0].second;
        // cout<<verticalBoundaries[0].first<<" "<<verticalBoundaries[0].second<<" "<<verticalLast<<endl;
        for(int i=1; i<N; i++) {
            if(verticalBoundaries[i].first < verticalLast)
                verticalLast = max(verticalLast, verticalBoundaries[i].second);
            else {
                cut++;
                verticalLast = verticalBoundaries[i].second;
            }
            // cout<<verticalBoundaries[i].first<<" "<<verticalBoundaries[i].second<<" last = "<<verticalLast<<" "<<cut<<endl;
            if(cut==2)
                return true;
        }
        // cout<<"vertical cuts "<<cut<<endl;
        cut = 0;
        int horizontalLast = horizontalBoundaries[0].second;
        // cout<<horizontalBoundaries[0].first<<" "<<horizontalBoundaries[0].second<<" "<<horizontalLast<<endl;
        for(int i=1; i<N; i++) {
            if(horizontalBoundaries[i].first < horizontalLast)
                horizontalLast = max(horizontalLast, horizontalBoundaries[i].second);
            else {
                cut++;
                horizontalLast = horizontalBoundaries[i].second;
            }
            // cout<<horizontalBoundaries[i].first<<" "<<horizontalBoundaries[i].second<<" last = "<<horizontalLast<<" "<<cut<<endl;
            if(cut==2)
                return true;
        }
        // cout<<"horizontal cuts "<<cut<<endl;
        return false;
    }
};
