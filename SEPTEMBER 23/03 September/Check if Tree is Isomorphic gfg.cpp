class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool check(Node* root1, Node* root2)
    {
        if(!root1 || !root2)
            return true;
        if(root1->data != root2->data)
            return false;
        int left1 = (root1->left) ? (root1->left->data) : 0;
        int left2 = (root2->left) ? (root2->left->data) : 0;
        int right1 = (root1->right) ? (root1->right->data) : 0;
        int right2 = (root2->right) ? (root2->right->data) : 0;
        
        bool checked = false;
        if(left1==right2 && left2==right1)
            checked |= check(root1->left, root2->right) && check(root1->right, root2->left);
        
        if(left2==left1 && right2==right1)
            checked |= check(root1->left, root2->left) && check(root1->right, root2->right);
            
        return checked;
        
    }
    bool isIsomorphic(Node *root1,Node *root2)
    {
    //add code here.
        return check(root1, root2);
    }
};
