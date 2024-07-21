class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> rowAdjacency(k+1), colAdjacency(k+1);
        vector<int> rowDegree(k+1), colDegree(k+1);
        for(auto condition:rowConditions)
        {
            // condition = {from, to}
            rowAdjacency[condition[0]].push_back(condition[1]);
            rowDegree[condition[1]]++;
        }

        for(auto condition:colConditions)
        {
            // condition = {from, to}
            colAdjacency[condition[0]].push_back(condition[1]);
            colDegree[condition[1]]++;
        }

        vector<vector<int>> matrix(k,vector<int>(k));
        vector<vector<int>> positions(k+1,vector<int>(2,-1));
        vector<vector<int>> blanck;

        queue<int> q;
        for(int i=1; i<=k; i++)
        {
            if(rowDegree[i]==0)
                q.push(i);
        }

        int row = 0;
        while(!q.empty())
        {
            int elem = q.front();
            q.pop();
            positions[elem][0] = row++;
            for(int next:rowAdjacency[elem])
            {
                rowDegree[next]--;
                if(rowDegree[next]==0)
                    q.push(next);
            }
        }
        if(row!=k)
            return blanck;

        for(int i=1; i<=k; i++)
        {
            if(colDegree[i]==0)
                q.push(i);
        }
        int col = 0;
        while(!q.empty())
        {
            int elem = q.front();
            q.pop();
            positions[elem][1] = col++;
            for(int next:colAdjacency[elem])
            {
                colDegree[next]--;
                if(colDegree[next]==0)
                    q.push(next);
            }
        }
        if(col!=k)
            return blanck;

        for(int i=1; i<=k; i++)
        {
            matrix[positions[i][0]][positions[i][1]] = i;
        }

        return matrix;
    }
};
