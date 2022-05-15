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


/* Solution idea:
                  It is simple DFS implementation clubbed with maxDepth calculation
*/

class Solution {
public:
    int tree_height(TreeNode *root){
        if(!root) return 0;
        else return max(tree_height(root->left), tree_height(root->right))+1;
    }
    
    int level(int height, TreeNode *root){
        int sum=0;
        if(!root) return sum;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *node;
        int size;
        for(int h=1;h<=height;h++){
            size=q.size();
            for(int i=0;i<size;i++){
                node=q.front();
                q.pop();
                if(!node) continue;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        size=q.size();
        for(int i=0;i<size;i++)
        {
            node=q.front();
            q.pop();
            if(!node) continue;
            sum+=node->val;
        }
        return sum;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        int height;
        height=max(tree_height(root->right),tree_height(root->left));
        int sum=level(height,root);
        return sum;
    }
};
