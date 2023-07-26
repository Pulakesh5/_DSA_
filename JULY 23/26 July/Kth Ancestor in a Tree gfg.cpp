void count(Node* root, int &N, vector<int> &parents)
{
    if(!root)
        return;
    N++;
    // cout<<"visited "<<root->data<<endl;
    if(root->left)
    {
        parents[root->left->data] = root->data;
        count(root->left, N, parents);
    }
    if(root->right)
    {
        parents[root->right->data] = root->data;
        count(root->right, N, parents);    
    }
    
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int N=0;
    
    // cout<<N<<endl;
    vector<int> parents(1e5+5,-1);
    count(root, N, parents);
    // for(int i=1; i<5; i++)
    //     cout<<i<<" "<<parents[i]<<endl;
    int parent = node;
    while(k && parent!=-1)
    {
        // cout<<k<<" "<<parent<<endl;
        k--;
        parent = parents[parent];
    }
    // cout<<k<<" "<<parent<<endl;
    return parent;
}
