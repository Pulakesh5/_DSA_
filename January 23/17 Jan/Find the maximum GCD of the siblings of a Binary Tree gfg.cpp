    int ans=0;
    Node* node=NULL;;
    int _maxGCD=0;
    int maxGCD( Node* root)
    {
        //code here
        if(!root) return 0;
        
        dfs(root);
        return (_maxGCD==0)?0:node->data;
    }
    int dfs(Node* root)
    {
        if(!root) return 0;
        
        //(root->left? (root->left->data) : (root->right?root->right->data:0));
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if(left==0 || right==0)
            return root->data;
        
        int    gcd=__gcd(root->right->data,root->left->data);
            //cout<<gcd<<" ";
        
        if(gcd>_maxGCD)
        {
            node=root;
            _maxGCD=gcd;
        }
        
        return root->data;
        //cout<<"\ncalled "<<root->data<<" "<<gcd<<" "<<_maxGCD<<endl;
    }
    
