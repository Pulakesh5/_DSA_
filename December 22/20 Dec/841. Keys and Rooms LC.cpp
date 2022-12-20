class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n+5,0);

        queue<int> q;
        q.push(0);
        visited[0]=true;

        while(!q.empty())
        {
            int room=q.front();
            q.pop();
            for(int rm:rooms[room])
            {
                if(!visited[rm])
                {
                    visited[rm]=true;
                    q.push(rm);
                }
            }
        }
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            flag&=visited[i];
        }
        return flag;
    }
};
