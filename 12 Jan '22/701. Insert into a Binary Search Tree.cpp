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
//Recursive solution
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return  new TreeNode(val);
        }
        if(val<(root->val)) 
            root->left = insertIntoBST(root->left, val);
        else if( val>root->val) 
            root->right = insertIntoBST(root->right,val);
        return root;

    }
};
//Iterative Solution
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode *current=root;
        if(!current) return new TreeNode(val);
        while(current){
            if(current->val > val){
                if(current->left) current = current->left;
                else{
                    current->left = new TreeNode(val);
                    break;
                }
            }
            else{
                if(current->right) current = current->right;
                else{
                    current->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;

    }
};
