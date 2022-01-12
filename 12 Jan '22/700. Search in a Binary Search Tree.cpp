/*
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
 //Recursive Solution
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root || root->val==val)
            return root;
        else if(val<root->val)
            return searchBST(root->left,val);
        else
            return searchBST(root->right, val);
    }
};
//Iterative Solution
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        TreeNode *current=root;
        while(current){
            if(current->val == val)
                return current;
            else if(current->val > val)
                current=current->left;
            else
                current=current->right;
        }
        return NULL;
        
    }
};
