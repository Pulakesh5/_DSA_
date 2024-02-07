class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int ans;
    int traverse(Node* root, int a, int b)
    {
        if(root == nullptr)
            return -1;
        
        int left = traverse(root->left, a, b);
        int right = traverse(root->right, a, b);
        if(root->data==a || root->data==b)
        {
            if(left!=-1)
            {
                ans = left;
                return -1;
            }
            if(right!=-1)
            {
                ans = right;
                return -1;
            }
            return 1;
        }
        else
        {
            if(left == right && left == -1)
                return -1;
            if(left==-1)
                return 1+right;
            if(right==-1)
                return 1+left;
            ans = left+right;
            return -1;
        }
        return -1;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        if(a==b)
            return 0;
        traverse(root, a, b);
        return ans;
    }
};
