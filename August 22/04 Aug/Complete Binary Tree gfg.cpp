class Solution{
public:    
    bool isCompleteBT(Node* root){
        //code here
        queue<Node*> q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node *node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    if(!flag) return false;
                }
                else{
                    flag=false;
                }
                if(node->right){
                    q.push(node->right);
                    if(!flag) return false;
                }
                else{
                    flag=false;
                }
            }
        }
        return true;
    }
    
};
