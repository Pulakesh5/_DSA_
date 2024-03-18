class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
        queue<Node*> q;
        q.push(root);
        int qsize;
        vector<int> traversal;
        while(!q.empty())
        {
            qsize = q.size();
            for(int i=0; i<qsize; i++)
            {
                Node* node = q.front();
                q.pop();
                traversal.push_back(node->data);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return traversal;
    }
};
