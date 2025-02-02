class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>> traversals;
        queue<Node*> q;
        q.push(root);
        Node* node;
        
        while(!q.empty())
        {
            int qsize = q.size();
            vector<int> level;
            for(int i=0; i<qsize; i++)
            {
                node = q.front();
                q.pop();
                
                if(node->left)
                    q.push(node->left);
                
                if(node->right)
                    q.push(node->right);
                    
                level.push_back(node->data);
            }
            traversals.push_back(level);
        }
        
        return traversals;
    }
};
