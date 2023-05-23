Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        int ind=0;
        return help(pre,preMirror,ind,0,size-1,size);
    }
    Node* help(int pre[], int preMirror[], int &ind, int l, int h, int size)
    {
        if(ind>=size || l>h) return NULL;
        
        Node* root= new Node(pre[ind]);
        ind++;
        
        if(l==h) return root;
        
        int i;
        for(i=l;i<=h;i++){
            if(preMirror[i]==pre[ind]) break;
        }
        
        if(i<=h){
            root->left= help(pre, preMirror,ind,i,h,size);
            root->right= help(pre, preMirror,ind,l+1,h-1,size);
        }
        return root;
    }
