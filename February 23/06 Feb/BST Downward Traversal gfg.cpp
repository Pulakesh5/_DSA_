    long long sumBST(Node* _root, int col)
    {
        if(!_root) return 0;
        long long sum=0;
        if(col==0) sum = _root->data;
        
        sum+=sumBST(_root->left,col-1);
        sum+=sumBST(_root->right,col+1);
        
        return sum;
    }
    long long int verticallyDownBST(Node *root,int target){
        // Code here
        Node* _root=root;
        while(_root && _root->data!=target)
        {
            //cout<<_root->data<<" ";
            if(_root->data < target) 
                _root=_root->right;
            else if(_root->data > target) 
                _root=_root->left;
            else
                _root=NULL;
        }
        //cout<<endl;
        
        if(_root) return sumBST(_root->left,-1)+sumBST(_root->right,1);
        return -1;
    }
