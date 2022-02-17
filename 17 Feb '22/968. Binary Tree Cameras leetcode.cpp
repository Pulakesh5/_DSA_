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
    int camera=0;
    int helper(TreeNode *root){
        if(!root) return 1;
        int lt=helper(root->left);
        int rt=helper(root->right);
        if(lt==-1 || rt==-1)
        {
            camera++;
            return 0;
        }
        if(lt==0 || rt==0)
            return 1;
        
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(helper(root)==-1)
            camera++;
        return camera;
    }
};
