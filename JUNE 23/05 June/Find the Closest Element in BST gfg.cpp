class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
	int minDifference = INT_MAX;
    int minDiff(Node *root, int K)
    {
        //Your code here
        traverse(root,K);
        return minDifference;
    }
    void traverse(Node* root, int K)
    {
        minDifference = min(minDifference, abs(root->data - K));
        if(root->data==K) return;
        if(root->left && root->data > K) traverse(root->left, K);
        else if(root->right && root->data < K) traverse(root->right, K);
    }
};
