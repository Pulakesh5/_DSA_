
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    int ans=findCeil(root->left,input);
    if(ans!=-1 && ans>=input) return ans;
    
    if(root->data >= input) return root->data;
    
    ans=findCeil(root->right, input);
    if(ans!=-1 && ans>=input) return ans;
    
    return -1;
    // Your code here
}
