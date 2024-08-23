void traverse(Node* root, vector<int> &view, int depth)
{
    if(root==nullptr)
        return;
    if(depth>view.size())
        view.push_back(root->data);
    traverse(root->left, view, depth+1);
    traverse(root->right, view, depth+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> view;
   traverse(root, view, 1);
   return view;
}
