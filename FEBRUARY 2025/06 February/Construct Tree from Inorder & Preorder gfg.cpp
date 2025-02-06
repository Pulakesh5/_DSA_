class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node* treeRoot = nullptr;
    Node* build(vector<int> &in, int in_l, int in_r, vector<int> &pre, int pre_l, int pre_r)
    {
        if(pre_l>pre_r || in_l>in_r)
            return nullptr;
        
        Node* treeNode;
        
        int i;
        for(i=in_l; i<=in_r; i++)
        {
            if(in[i]==pre[pre_l])
            {
                treeNode = new Node(pre[pre_l]);
                break;
            }
        }
        
        int ltree = i-in_l, rtree = in_r-i;
        
        treeNode->left = build(in, in_l, i-1, pre, pre_l+1, pre_l+ltree);
        treeNode->right = build(in, i+1, in_r, pre, pre_l+ltree+1, pre_r);
        
        return treeNode;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n = inorder.size();
        return build(inorder, 0, n-1, preorder, 0, n-1);
    }
};
