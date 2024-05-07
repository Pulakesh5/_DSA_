class Solution
{
    private: 
    pair<bool,int> check(Node* root)
    {
        if(root==nullptr)
            return {true,0};
        if(root->left==nullptr && root->right==nullptr)
            return {true, root->data};
        
        pair<bool,int> lTree = check(root->left);
        pair<bool,int> rTree = check(root->right);
        
        // int lVal = (root->left? root->left->data : 0);
        // int rVal = (root->right? root->right->data : 0);
        int lVal = lTree.second, rVal = rTree.second;
        return {(lTree.first && rTree.first && ((root->data)==(lVal+rVal))), (lVal+rVal+root->data)};
    }
    public:
    bool isSumTree(Node* root)
    {
        // Your code here
        return check(root).first; 
    }
};
