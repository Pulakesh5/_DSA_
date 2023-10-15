class Solution{
    
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    void traverse(vector<int> &values, Node* root)
    {
        if(!root)
            return;
        traverse(values, root->left);
        values.push_back(root->data);
        traverse(values, root->right);
    }
    Node* makeBST(vector<int> &values, int l, int r)
    {
        if(l>r)
            return nullptr;
        int mid = (l+r)/2;
        Node* root = new Node(values[mid]);
        root->left = makeBST(values, l, mid-1);
        root->right = makeBST(values, mid+1, r);
        return root;
    }
    Node* buildBalancedTree(Node* root)
    {
    	// Code here
    	vector<int> values;
    	traverse(values, root);
    	int l = 0, r = values.size()-1;
    	return makeBST(values, l, r);
    }
};
