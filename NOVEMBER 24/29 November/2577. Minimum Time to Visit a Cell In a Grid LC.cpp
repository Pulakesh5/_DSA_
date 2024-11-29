class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        if(grid[0][0]>0 || (grid[0][1]>1 && grid[1][0]>1))
            return -1;

        int R = grid.size(), C = grid[0].size();
        // cout<<"R: "<<R<<" C: "<<C<<endl;
        pq.push({0, 0, 0});
        grid[0][0] = INT_MIN;

        // if(grid[0][1]<=1)
        // {
        //     pq.push({1, 0, 1});
        //     if(grid[0][1] == 0)
        //         grid[0][1] = INT_MIN;
        //     else
        //         grid[0][1] = -1*grid[0][1];
        // }

        // if(grid[1][0]<=1)
        // {
        //     pq.push({1, 1, 0});
        //     if(grid[1][0] == 0)
        //         grid[1][0] = INT_MIN;
        //     else
        //         grid[1][0] = -1*grid[1][0];
        // }


        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        int timestamp, x, y, nx, ny, extra;
        while(!pq.empty())
        {
            vector<int> node = pq.top();
            pq.pop();
            timestamp = node[0];
            x = node[1];
            y = node[2];
            // cout<<x<<" "<<y<<endl;
            if(x==R-1 && y==C-1)
                return timestamp;
            
            timestamp++;
            for(int k=0; k<4; k++)
            {
                nx = x+dx[k];
                ny = y+dy[k];
                // cout<<"\tChecking : "<<nx<<" "<<ny<<endl;
                if(nx>=0 && nx<R && ny>=0 && ny<C && grid[nx][ny]>=0)
                {
                    if(grid[nx][ny]<=timestamp)
                    {
                        // cout<<"\tPushing "<<nx<<" "<<ny<<" with t= "<<timestamp<<endl;
                        pq.push({timestamp, nx, ny});
                    }
                    else{
                        extra = 2*((grid[nx][ny]-timestamp+1)/2);
                        pq.push({timestamp+extra, nx, ny});
                        // cout<<"\tPushing "<<nx<<" "<<ny<<" with t= "<<timestamp+extra<<endl;
                    }
                    if(grid[nx][ny]==0)
                        grid[nx][ny] = INT_MIN;
                    else
                        grid[nx][ny] = -1*grid[nx][ny];
                }
            }
        }
        // control should not reach here
        return -1;
    }
};

/*
0 1  99
3 99 99
4 5  6
*/
