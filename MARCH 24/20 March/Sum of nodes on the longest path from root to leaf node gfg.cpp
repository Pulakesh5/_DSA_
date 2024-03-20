class Solution
{
public:
    int maxDepth = -1, sum=0;
    void traverse(Node* root, int parent, int depth)
    {
        if(root==nullptr)
            return;
        if(depth>maxDepth)
        {
            maxDepth = depth;
            sum = parent+root->data;
        }
        else if(depth==maxDepth)
        {
            sum = max(sum, parent+root->data);
        }
        // cout<<root->data<<" : "<<sum<<", "<<depth<<endl;
        traverse(root->left, parent+root->data, depth+1);
        traverse(root->right, parent+root->data, depth+1);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        traverse(root, 0, 0);
        return sum;
    }
};
