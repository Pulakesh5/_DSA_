
class Solution
{
    private:
    Node* findLCA(Node* root, int x, int y, vector<int> &path)
    {
        if(root==nullptr)
            return NULL;
        
        path.push_back(root->data);
        
        if(root->data>x && root->data>y)
            return findLCA(root->left, x, y, path);
        
        else if(root->data<x && root->data<y)
            return findLCA(root->right, x, y, path);
        
        return root;
    }
    public:
    
    /*You are required to complete below function */
    
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        vector<int> path;
        
        Node* ans = findLCA(root, x, y, path);
        
        if(path.size()<k)
            return -1;
        return path[path.size()-k];
    }
};
