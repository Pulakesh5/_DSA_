class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    bool check(Node* root)
    {
        if(root == nullptr || (root->left==nullptr && root->right==nullptr))
            return true;
        int left = check(root->left);
        int right = check(root->right);
        int sum=0;
        if(root->left)
            sum+=root->left->data;
        if(root->right)
            sum+=root->right->data;
        // cout<<root->data<<" : "<<left<<", "<<right<<", "<<sum<<endl;
        if(left && right && sum==root->data)
            return true;
        
        return false;
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
        return check(root);
    }
};
