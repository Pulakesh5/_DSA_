class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        bitset<1000000> visited;
        for(int i=0;i<N;i++)
        {
            if(frogs[i]<=leaves && !visited[frogs[i]])
            {
                for(int leave=frogs[i];leave<=leaves;leave+=frogs[i])
                {
                    visited.set(leave);
                }
            }
        }
        int unvisited=leaves-visited.count();;
        
        return unvisited;
    }
};
