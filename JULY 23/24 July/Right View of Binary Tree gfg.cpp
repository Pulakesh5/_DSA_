class Solution
{
    
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> ans;
    void right_view(Node* root, int level)
    {
        if(!root)
            return;
        if(level > ans.size())
            ans.push_back(root->data);
        right_view(root->right, level+1);
        right_view(root->left, level+1);
    }
    vector<int> rightView(Node *root)
    {
       // Your Code here
       right_view(root,1);
       return ans;
    }
};
