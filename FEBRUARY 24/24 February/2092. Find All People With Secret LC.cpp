class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<vector<int>>> adj(n+5);
        
        for(auto meeting:meetings)
        {
            // cout<<meeting[0]<<" "<<meeting[1]<<" "<<meeting[2]<<endl;
            adj[meeting[0]].push_back({meeting[2], meeting[1]});
            adj[meeting[1]].push_back({meeting[2], meeting[0]});
        }
        // for(int i=0; i<n; i++)
        // {
        //     cout<<i<<" : ";
        //     for(auto meeting:adj[i])
        //         cout<<"{"<<meeting[0]<<", "<<meeting[1]<<"} ";
        //     cout<<endl;
        // }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;
        vector<bool> visited(n+5,0);
        q.push({0,firstPerson});
        q.push({0,0});
        
        while(!q.empty())
        {
            pair<int,int> meeting=q.top();
            q.pop();

            if(visited[meeting.second])
                continue;
            
            visited[meeting.second] = true;
            // cout<<meeting.second<< " "<<meeting.first<<" : ";
            for(auto next:adj[meeting.second])
            {
                // cout<<next[0]<<" ";
                if(!visited[next[1]] && next[0] >= meeting.first)
                {
                    
                    q.push({next[0], next[1]});
                }
                
            }
            cout<<endl;
        }

        vector<int> personWithSecret;
        for(int i=0; i<n; i++)
        {
            if(visited[i])
                personWithSecret.push_back(i);
        }

        return personWithSecret;
    }
};
