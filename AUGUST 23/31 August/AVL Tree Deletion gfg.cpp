void traversal(vector<int> &vec, Node* root, int data)
{
    if(!root)
        return;
    traversal(vec, root->left, data);
    if(root->data != data) vec.push_back(root->data);
    traversal(vec, root->right, data);
}
Node* makeAVLTree(vector<int> &nodes, int l, int r)
{
    if(l>r)
        return NULL;
    int mid = l+(r-l)/2;
    Node* node = new Node(nodes[mid]);
    node->left = makeAVLTree(nodes, l, mid-1);
    node->right = makeAVLTree(nodes, mid+1, r);
    return node;
}
Node* deleteNode(Node* root, int data)
{
    //add code here,
    vector<int> vec;
    traversal(vec, root, data);
    return makeAVLTree(vec, 0, vec.size()-1);
}
