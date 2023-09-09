class Solution
{
    public:
    int kLargest=-1;
    void traverse(Node* root, int &K)
    {
        if(!root)
            return;
        traverse(root->right,K);
        // cout<<root->data<<" "<<K<<endl;
        K--;
        if(K==0)    
            kLargest = root->data;
        traverse(root->left,K);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        traverse(root, K);
        return kLargest;
    }
};
