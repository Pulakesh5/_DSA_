 class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    void inorder(Node *root, vector<int> &ans) {
        if(root) {
            inorder(root->left, ans);
            ans.push_back(root->data);
            inorder(root->right, ans);
        }
    }
    Node *bTreeToCList(Node *root)
    {
    //add code here.
        if(!root)
            return NULL;
            
        vector<int> v;
        inorder(root, v);
        
        Node *dummy = newNode(0);
        Node *p = dummy, *pre = NULL;
        
        for(auto num: v) {
            p->right = newNode(num);
            p = p->right;
            p->left = pre;
            pre = p;
        }
        
        p->right = dummy->right;
        dummy->right->left = p;
        
        return dummy->right;
        
    }
};
