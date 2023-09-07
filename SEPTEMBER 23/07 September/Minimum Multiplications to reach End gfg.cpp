class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<bool> visited(1e5+5,false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        int qSize, curr, num_, step=0, lim = 1e5;
        while(!q.empty())
        {
            qSize = q.size();
            for(int i=0; i<qSize; i++)
            {
                curr = q.front();
                q.pop();
                // cout<<curr<<" ";
                if(curr==end)
                    return step;
                for(int num:arr)
                {
                    num_ = (curr*num)%lim;
                    if(!visited[num_])
                    {
                        visited[num_] = true;
                        q.push(num_);
                    }
                }
            }
            step++;
        }
        // cout<<endl;
        return -1;
    }
};
