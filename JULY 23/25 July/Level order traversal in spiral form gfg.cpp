vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> traversal;
    int reverse = 1;
    int qSize;
    Node* node;
    deque<Node*> q;
    q.push_front(root);
    
    while(!q.empty())
    {
        qSize = q.size();
        // cout<<reverse<<endl;
        if(reverse==0)
        {
            for(int i=0; i<qSize; i++)
            {
                node = q.front();
                q.pop_front();
                // cout<<node->data<<" ";
                traversal.push_back(node->data);
                if((node->left))   q.push_back(node->left);
                if((node->right))  q.push_back(node->right);
            }
        }
        else
        {
            for(int i=0; i<qSize; i++)
            {
                node = q.back();
                q.pop_back();
                // cout<<node->data<<" ";
                traversal.push_back(node->data);
                if((node->right))  q.push_front(node->right);
                if((node->left))   q.push_front(node->left);
            }
        }
        // cout<<endl;
        reverse = 1 - reverse;
    }
    
    return traversal;
    // traverse(traversal, reverse);
    
            //         19
            //     6       23
            // 3      9 21     N
    
    
}
