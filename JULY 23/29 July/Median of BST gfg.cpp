void traverse(struct Node* root, vector<float> &traversal)
{
    if(!root)
        return;
    traverse(root->left, traversal);
    traversal.push_back(root->data);
    traverse(root->right, traversal);
}
float findMedian(struct Node *root)
{
      //Code here
    vector<float> traversal;
    traverse(root, traversal);
    int N = traversal.size();
    if(N%2)
        return traversal[N/2];
    else
        return (traversal[N/2] + traversal[(N-1)/2])/2;
}
