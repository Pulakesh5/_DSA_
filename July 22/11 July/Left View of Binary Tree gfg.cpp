vector<int> ans;
int maxHeight=-1;
void fun(Node *root, int height){
    if(!root) return;
    //cout<<root->data<<" "<<height<<" "<<maxHeight<<'\n';
    if(height>maxHeight){
        maxHeight=height;
        ans.push_back(root->data);
    }
    fun(root->left,height+1);
    fun(root->right,height+1);
}
vector<int> leftView(Node *root)
{
   // Your code here
   ans.clear();
   maxHeight=-1;
   fun(root,0);
   return ans;
}
