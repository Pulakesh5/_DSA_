Node * bToDLL(Node *root)
    {
        // your code here
       
        return rec(root);
    }
    
    Node* rec(Node* root){
        if(!root) return root;

        Node *leftTree=rec(root->left);
        Node *rightTree=rec(root->right);
        
        Node *leftEnd=leftTree;
        
        while(leftTree && leftEnd->right) 
            leftEnd=leftEnd->right;
        
        if(leftTree)
        {
            leftEnd->right=root;
        }
        if(rightTree)
        {
            rightTree->left=root;
        }
            
            
        root->left=leftEnd;
        root->right=rightTree;
        if(leftTree)
            return leftTree;
        return root;
    }
