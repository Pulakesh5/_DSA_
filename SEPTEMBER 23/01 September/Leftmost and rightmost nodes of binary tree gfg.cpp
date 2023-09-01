void printCorner(Node *root)
{

// Your code goes here

    if(!root)
        return;
    
    queue<Node*> q;
    q.push(root);
    Node* node;
    int qs;
    while(!q.empty())
    {
        qs = q.size();
        for(int i=0; i<qs; i++)
        {
            node = q.front();
            q.pop();
            
            if(i==0 || i==qs-1)
                cout<<node->data<<" ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
    
}
