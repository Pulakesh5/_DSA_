class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_map<int, int> parent;
        for(auto desc:descriptions)
        {
            if(nodes.find(desc[0])==nodes.end())
                nodes[desc[0]] = new TreeNode(desc[0]);
            
            if(nodes.find(desc[1])==nodes.end())
                nodes[desc[1]] = new TreeNode(desc[1]);
                
            parent[desc[1]] = desc[0];

            if(desc[2])
                nodes[desc[0]]->left = nodes[desc[1]];
            else
                nodes[desc[0]]->right = nodes[desc[1]];
        }
        int intRoot = -1;
        for(auto it:nodes)
        {
            if(parent.find(it.first)==parent.end())
            {
                intRoot = it.first;
                break;
            }
        }
        return nodes[intRoot];
    }
};
