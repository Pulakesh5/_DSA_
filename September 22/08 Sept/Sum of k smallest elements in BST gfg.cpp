void _sum(Node* root,int &k, int &sum)
{
    if(!root || k==0) return;
    _sum(root->left,k,sum);
    if(k!=0)
    {
        sum+=(root->data);
        k--;
    }
    else
        return;
    _sum(root->right,k,sum);
}


int sum(Node* root, int k) 
{
    // Your code here
    int sum=0;
    _sum(root,k,sum);
    return sum;
} 
