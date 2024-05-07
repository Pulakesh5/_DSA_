vector<int> reverseLevelOrder(Node *root)
{
    // code here
    queue<Node*> q;
    q.push(root);
    vector<int> traversal;
    while(!q.empty())
    {
        int qsize = q.size();
        for(int i=0; i<qsize; i++)
        {
            Node* node = q.front();
            q.pop();
            traversal.push_back(node->data);
            if(node->right)
                q.push(node->right);
            if(node->left)
                q.push(node->left);
        }
        
    }
    reverse(traversal.begin(), traversal.end());
    return traversal;
}
