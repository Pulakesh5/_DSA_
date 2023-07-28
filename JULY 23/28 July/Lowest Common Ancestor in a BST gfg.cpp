class Solution{
    public:
        
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            if(!root)   return NULL;
            if(root->data == n1 || root->data == n2)
                return root;
            Node* left = LCA(root->left, n1, n2);
            Node* right = LCA(root->right, n1, n2);
            
            if(!left)
                return right;
            else if(!right)
                return left;
            return root;
        }

};
