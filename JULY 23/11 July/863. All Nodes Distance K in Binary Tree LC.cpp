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
    vector<int> nodes;
    map<TreeNode*, TreeNode*> parent;//son=>parent
    set<TreeNode*> visited;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return nodes;
        
        findParent(root);
        Kdistance(target,k);
        return nodes;
    }
private:
    void findParent(TreeNode *root){
        if(!root) return;
        if(root->left){
            parent[root->left]=root;
            findParent(root->left);
        }
        if(root->right){
            parent[root->right]=root;
            findParent(root->right);
        }
    }
    void Kdistance(TreeNode* root, int k){
        if(!root) return;
        if(visited.find(root)!=visited.end()) return;
        visited.insert(root);
        if(k==0){
            nodes.push_back(root->val);
            return;
        }
        if(root->left){
            Kdistance(root->left,k-1);
        }
        if(root->right){
            Kdistance(root->right,k-1);
        }
        TreeNode *pr=parent[root];
        Kdistance(pr,k-1);
        return;
    }
    
};
