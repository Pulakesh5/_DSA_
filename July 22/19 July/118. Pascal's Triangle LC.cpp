class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});
        int num;
        for(int l=2;l<=numRows;l++){
            vector<int> row(l);
            row[0]=1; row[l-1]=1;
            for(int i=1;i<(l-1) ;i++)
                row[i]=triangle[l-2][i]+triangle[l-2][i-1];
            triangle.push_back(row);
        }
        return triangle;
    }
};
