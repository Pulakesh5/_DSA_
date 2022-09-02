class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        double sum=0;
        int qsize;
        vector<double> levelAvg;
        
        while(!q.empty())
        {
            qsize=q.size();
            sum=0;
            for(int i=0;i<qsize;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            levelAvg.push_back(sum/qsize);
        }
        
        return levelAvg;
    }
};
