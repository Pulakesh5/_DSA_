class Solution
{
    public:
    vector<vector<int>> paths;
    void traverse(Node* root, int s, int sum, vector<int> path)
    {
        if(!root)
            return;
        s+=root->key;
        path.push_back(root->key);
        if(s==sum)
            paths.push_back(path);
        traverse(root->left, s, sum, path);
        traverse(root->right, s, sum, path);
    }
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        vector<int> path;
        traverse(root, 0, sum, path);
        return paths;
    }
};
