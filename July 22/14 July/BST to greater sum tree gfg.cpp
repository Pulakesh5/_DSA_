class Solution
{
    public:
    int GST(Node *root, int &ParentSum){
        if(!root){
            return 0;
        }
        int ChildSum = GST(root->right,ParentSum);
        ParentSum+=ChildSum;
        ParentSum+=(root->data);
        root->data=ParentSum-root->data;
        return GST(root->left,ParentSum);
    }
    void transformTree(struct Node *root)
    {
        //code here
        int ParentSum=0;
        GST(root,ParentSum);
    }
};
