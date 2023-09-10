    Node* insert(Node* root, int Key) {
        if(root->data<Key) {
            if(root->right) return insert(root->right,Key);
            else return root->right=new Node(Key);
        }
        else if(root->data>Key){
            if(root->left) return insert(root->left,Key);
            else return root->left=new Node(Key);
        }
        return root;
    }
