vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   queue<Node*> q;
    if(root)
    q.push(root);
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        while(node){
            ans.push_back(node->data);
            if(node->left) q.push(node->left);
            node=node->right;
        }
    }
    
    return ans;
}
