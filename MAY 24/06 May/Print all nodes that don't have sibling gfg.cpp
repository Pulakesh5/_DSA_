void findNoSibling(Node *node, vector<int> &noSiblings)
{
    if(node==nullptr)
        return;
    
    if((node->left!=nullptr && node->right==nullptr))
    {
        noSiblings.push_back(node->left->data);
        findNoSibling(node->left, noSiblings);
    }
    else if((node->left==nullptr && node->right!=nullptr))
    {
        noSiblings.push_back(node->right->data);  
        findNoSibling(node->right, noSiblings);
    }
    else
    {
        findNoSibling(node->left, noSiblings);
        findNoSibling(node->right, noSiblings);
    }
    
}

vector<int> noSibling(Node* root)
{
    // code here
    if(root==nullptr)
        return {-1};
    vector<int> noSiblings;
    
    findNoSibling(root, noSiblings);
    sort(noSiblings.begin(), noSiblings.end());
    if(noSiblings.size())
        return noSiblings;
    return {-1};
}
