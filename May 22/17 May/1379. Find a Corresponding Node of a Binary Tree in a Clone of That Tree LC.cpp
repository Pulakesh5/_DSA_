/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q_original,q_cloned;
        bool found=false;
        q_original.push(original);
        q_cloned.push(cloned);
        
        TreeNode *node_org,*node_cln;
        while(!found){
            int sz=q_cloned.size();
            for(int i=0;i,sz;i++){
                node_org=q_original.front();
                node_cln=q_cloned.front();
                q_original.pop();
                q_cloned.pop();
                
                if(node_org==target){
                    return node_cln;
                }
                if(node_org->left){
                    q_original.push(node_org->left);
                    q_cloned.push(node_cln->left);
                }
                if(node_org->right){
                    q_original.push(node_org->right);
                    q_cloned.push(node_cln->right);
                }
            }
        }
        return original;
    }
};
