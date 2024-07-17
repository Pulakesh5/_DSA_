class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
        int N = parent.size();
        vector<vector<int>> adjList(N);
        vector<Node*> nodes(N, nullptr);
        int rootVal = -1;
        for(int i=0; i<N; i++)
        {
            if(parent[i]==-1)
                rootVal = i;
            else
                adjList[parent[i]].push_back(i);
        }

        nodes[rootVal] =  new Node(rootVal);
        queue<Node*> q;
        q.push(nodes[rootVal]);
        while(!q.empty())
        {
            Node* currNode = q.front();
            q.pop();
            // cout<<currNode->data<<endl;
            
            for(int child:adjList[currNode->data])
            {
                if(nodes[child] == nullptr)
                {
                    nodes[child] = new Node(child);
                    q.push(nodes[child]);
                }
                if(currNode->left == nullptr)
                    currNode->left = nodes[child];
                else
                    currNode->right = nodes[child];
            }
        }
        return nodes[rootVal];
        
    }
};
