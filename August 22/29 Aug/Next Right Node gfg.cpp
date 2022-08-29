Node *nextRight(Node *root, int key)
    {
        //code here
        if(!root) return root;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int qsize=q.size();
            for(int i=0;i<qsize;i++){
                Node *frnt = q.front();
                q.pop();
                if(frnt->data == key && i<(qsize-1)){
                    return q.front();
                }
                if(frnt->left)
                    q.push(frnt->left);
                if(frnt->right)
                    q.push(frnt->right);
            }
            
        }
        
        return new Node(-1);
    }
