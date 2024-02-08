class Solution{
  public:
    /*You are required to complete this method*/
    bool checkSameLevel(Node* root, int level)
    {
        if(!root)
            return true;
        if(root->left == nullptr && root->right == nullptr)
        {
            if(leafLevel==-1)
                leafLevel = level;
            else if(level != leafLevel)
                return false;
            return true;
        }
        return checkSameLevel(root->left, level+1) && checkSameLevel(root->right, level+1);
    }
    // 4
    // 12 0
    // 11 
    bool check(Node *root)
    {
        //Your code here
        
        return checkSameLevel(root, 0);
    }
    private:
    int leafLevel=-1;
};
