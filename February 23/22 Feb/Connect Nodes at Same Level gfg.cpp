    void connect(Node *root)
    {
        queue<Node*> q;

        q.push(root);
        int qs;
        Node *node;
        while(!q.empty())
        {
            qs=q.size();
            while(qs)
            {
                node = q.front();
                q.pop();
                qs--;
                if(qs>0 && !q.empty())
                    node->nextRight=q.front();
                else if(qs==0 || q.empty())
                    node->nextRight=NULL;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);

            }
        }
    }   
