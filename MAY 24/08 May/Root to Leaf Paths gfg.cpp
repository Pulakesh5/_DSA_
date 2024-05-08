class Solution {
    private:
    void traverse(Node* root, vector<int> &path, vector<vector<int>> &paths)
    {
        if(root==nullptr)
            return;
        
        path.push_back(root->data);
        if(root->left==nullptr && root->right==nullptr)
        {
            paths.push_back(path);
        }
        else
        {
            traverse(root->left, path, paths);    
            traverse(root->right, path, paths);
        }
        path.pop_back();
    }
    public:
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>> paths;
        vector<int> path;
        traverse(root, path, paths);
        return paths;
    }
};
