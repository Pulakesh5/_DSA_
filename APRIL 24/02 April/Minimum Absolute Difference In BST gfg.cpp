class Solution
{
    private:
    long long minAbsoluteDifference = INT_MAX;
    long long prevValue = INT_MAX;
    void inorder(Node* root)
    {
        if(root==nullptr)
            return;
        inorder(root->left);
        
        minAbsoluteDifference = min(minAbsoluteDifference, abs(prevValue-root->data));
        prevValue = root->data;
        
        inorder(root->right);
    }
    //       15
    //    6      n
    //  1    8
    // n 5  n n 
    
    
    // 5
    // 3 7
    // 2 4 6 8
    public:
    int absolute_diff(Node *root)
    {
        //Your code here
        inorder(root);
        return minAbsoluteDifference;
    }
};
