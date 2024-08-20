class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        unordered_map<int, vector<int>> adjList;
        queue<Node*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            int N = nodes.size();
            for(int i=0; i<N; i++)
            {
                Node* node = nodes.front();
                nodes.pop();
                if(node->left)
                {
                    adjList[node->data].push_back(node->left->data);
                    adjList[node->left->data].push_back(node->data);
                    nodes.push(node->left);
                }
                if(node->right)
                {
                    adjList[node->data].push_back(node->right->data);
                    adjList[node->right->data].push_back(node->data);
                    nodes.push(node->right);
                }
                
            }
        }

        
        unordered_map<int,bool> visited;
        queue<pair<int,int>> q;
        q.push({target,0});
        visited[target] = true;
        int minimumTime = 0;
        
        while(!q.empty() )
        {
            pair<int,int> p = q.front();
            q.pop();
            
            minimumTime = max(minimumTime, p.second);
            for(int next:adjList[p.first])
            {
                if(!visited[next])
                {
                    q.push({next, p.second+1});
                    visited[next] = true;
                }
            }
            // cout<<endl;
            
        }
        return minimumTime;
    }
};
