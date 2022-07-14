/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,int> preorderIndex,inorderIndex; 
    vector<int> pre,in;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        if(n==0) return NULL;
        
        for(int i=0;i<n;i++)
            preorderIndex[preorder[i]]=i;
        for(int i=0;i<n;i++)
            inorderIndex[inorder[i]]=i;
        
        pre=preorder;
        in=inorder;
        
        int preleft=0,preright=n-1,inleft=0,inright=n-1;
        return binTree(preleft,preright,inleft,inright);
    }
    TreeNode* binTree(int preleft,int preright,int inleft,int inright)
    {
        if(preleft>preright || inleft>inright) return NULL;
        //int preIndex=preorderIndex[pre[preleft]];
        int inIndex=inorderIndex[pre[preleft]];
        TreeNode *root = new TreeNode(pre[preleft]);
        
        int leftDistance=inIndex-inleft;
        root->left = binTree(preleft+1,preleft+leftDistance,inleft,inIndex-1);
        int rightDistance=inright-inIndex;
        root->right = binTree(preleft+leftDistance+1,preleft+inright-inleft,inIndex+1, inright);
        return root;
    }
    
    
};
