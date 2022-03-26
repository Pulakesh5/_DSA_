void recur(Node *root, vector<int> &left,int depth,int &Max_Depth){
    if(!root) return;
    if(depth>Max_Depth){
        Max_Depth=depth;
        left.push_back(root->data);
    }
    recur(root->left,left,depth+1,Max_Depth);
    recur(root->right,left,depth+1,Max_Depth);
}

vector<int> leftView(Node *root)
{
   vector<int> left;
   int Max_Depth=-1;
   recur(root,left,1,Max_Depth);
   return left;
}
