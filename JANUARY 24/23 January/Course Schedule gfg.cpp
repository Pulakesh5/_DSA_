class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<vector<int>> dependent(n);
        vector<int> outdegree(n);
        for(vector<int> pre:prerequisites)
        {
            dependent[pre[1]].push_back(pre[0]);
            outdegree[pre[0]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(outdegree[i]==0)
                q.push(i);
        }
        
        vector<int> finished(n,0);
        vector<int> order;
        
        while(!q.empty())
        {
            bool possible=true;
            int course = q.front();
            q.pop();

            finished[course] = 1;
            order.push_back(course);

            for(int j=0; j<dependent[course].size(); j++)
            {
                int next = dependent[course][j];
                outdegree[next]--;
                if(outdegree[next]==0)
                    q.push(next);
            }
            
        }
        if(order.size()==n)
            return order;
        return {};
    }
};
