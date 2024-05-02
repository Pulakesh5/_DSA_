class Solution
{
    private:
    void inorder_traversal(Node* root, vector<int> &traversal)
    {
        if(root==nullptr)
            return;
        inorder_traversal(root->left, traversal);
        traversal.push_back(root->data);
        inorder_traversal(root->right, traversal);
    }
    Node* makeTree(vector<int> &traversal, int l, int r)
    {
        if(l>r)
            return nullptr;
        int mid = (l+r)/2;
        Node* lTree = makeTree(traversal, l, mid-1);
        Node* rTree = makeTree(traversal, mid+1, r);
        Node* node = new Node(traversal[mid]);
        node->left = lTree;
        node->right = rTree;
        return node;
    }
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> traversal;
        inorder_traversal(root, traversal);
        return traversal;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       return makeTree(A,0,A.size()-1);
    }

};
