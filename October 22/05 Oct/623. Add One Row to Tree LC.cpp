    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* head;
        if(depth==1){
            head = new TreeNode(val);
            head->left=root;
            return head;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        depth--;
        int qsize;
        TreeNode* node;
        
        while(depth>1)
        {
            qsize=q.size();
            //cout<<qsize<<"\n"<<"Pushed: ";
            for(int i=0;i<qsize;i++)
            {
                node=q.front();
                cout<<node->val<<" ";
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }
            //cout<<"\n"<<q.size();
            //cout<<endl;
            depth--;
        }
        
        qsize=q.size();
        for(int i=0;i<qsize;i++)
        {
            node=q.front();
            TreeNode* newNode; //= new TreeNode(val);
            
            newNode = new TreeNode(val);
            newNode->left=node->left;
            node->left=newNode;
            newNode = new TreeNode(val);
            newNode->right=node->right;
            node->right=newNode;
            q.pop();
        }
        return root;
    }
