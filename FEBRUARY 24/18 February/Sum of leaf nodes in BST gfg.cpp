class Solution
{
    public:
        /*You are required to complete below method */
        int leafSum(Node* root)
        {
            if(root==nullptr)
                return 0;
            if(root->left==nullptr && root->right==nullptr)
                return root->data;
            return leafSum(root->left)+leafSum(root->right);
        }
        int sumOfLeafNodes(Node *root ){
             /*Your code here */
            if(root==nullptr)
                return 0;
            return leafSum(root);
        }
};
