class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        vector<int> t;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                if(node && node->left) q.push(node->left);
                if(node && node->right) q.push(node->right);
                if(node) t.push_back(node->val);
            }
            ans.push_back(t);
            t.clear();
        }
        return ans;
    }
};
