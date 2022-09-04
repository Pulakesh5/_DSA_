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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        int column=0,row=0;
        _verticalTraversal(root,mp,column,row);
        
        int columns=mp.size();
        vector<vector<int>> verticalTraversal;
        
        int _col=0;
        for(auto &it:mp){
            vector<int> col;
            for(auto row:(it.second))
                col.insert(col.end(),row.second.begin(),row.second.end());
            
            verticalTraversal.push_back(col);
            _col++;
        }
        return verticalTraversal;
    }
    void _verticalTraversal(TreeNode* root, map<int,map<int,multiset<int>>> &mp, int column, int row)
    {
        if(!root) return;
        mp[column][row].insert(root->val);
        if(root->right) _verticalTraversal(root->right, mp, column+1,row+1);
        if(root->left) _verticalTraversal(root->left, mp, column-1,row+1);
        
    }
};
