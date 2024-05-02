class Solution
{
    public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
        // Your code here
        if(k==0)
            return {root->data};
        queue<struct Node*> q;
        q.push(root);
        int qsize;
        vector<int> kDistanceNodes;
        while(!q.empty())
        {
            qsize = q.size();
            kDistanceNodes.clear();
            for(int i=0; i<qsize; i++)
            {
                struct Node* node = q.front();
                kDistanceNodes.push_back(node->data);
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(k==0)
                return kDistanceNodes;
            k--;
        }
        return {};    
    }
};
