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
    TreeNode* deleteNodes(TreeNode* root, unordered_set<int> &nodes, bool parent, vector<TreeNode*> &forest)
    {
        if(root == nullptr)
            return nullptr;
        int rootVal = root->val;
        
        
        if(nodes.find(rootVal)==nodes.end())
        {
            if(parent == false)
                forest.push_back(root);
            TreeNode* lTree = deleteNodes(root->left, nodes, true, forest);
            TreeNode* rTree = deleteNodes(root->right, nodes, true, forest);
            root->left = lTree;
            root->right = rTree;
            return root;
        }
        else
        {
            TreeNode* lTree = deleteNodes(root->left, nodes, false, forest);
            TreeNode* rTree = deleteNodes(root->right, nodes, false, forest);
            root->left = lTree;
            root->right = rTree;
            return nullptr;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> nodes(to_delete.begin(), to_delete.end());
        bool parent = false;
        deleteNodes(root, nodes, parent, forest);
        return forest;
    }
};
