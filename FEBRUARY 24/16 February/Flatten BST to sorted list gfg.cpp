class Solution
{
public:
    Node *flattenBST(Node *root)
    {
        // code here
        if(root==nullptr)
            return nullptr;
        
        Node *leftTree=nullptr, *rightTree=nullptr;
        
        if(root->left)
            leftTree = flattenBST(root->left);
        if(root->right)
            rightTree = flattenBST(root->right);
        
        root->left = nullptr;
        root->right = rightTree;
        
        Node* head = leftTree;
        while(head && head->right)
            head = head->right;
        
        if(leftTree)
        {
            head->right = root;
            return leftTree;
        }
        return root;
    }
};
