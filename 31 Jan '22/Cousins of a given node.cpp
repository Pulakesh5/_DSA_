
/*
// A Binary Tree Node
struct Node
{
	int data;
	Node* left;
	Node* right;
};*/

// First thought to use DFS go with that
class Solution
{
    public:
    vector<int> printCousins(Node* root, Node* node_to_find)
    {
        queue<Node*> q;
        q.push(root);
        vector<int> ans;
        bool flag=false;
        while(!q.empty() &&!flag){
            
            // if(flag){
            //     while(!q.empty()){
            //         Node *nd=q.front();
            //         ans.push_back(q.front()->data);
            //         q.pop();
            //     }
            //     break;
            // }
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node *nd=q.front();
                q.pop();
                //cout<<sz<<" "<<nd->data<<'\n';
                if(nd->left==node_to_find || nd->right==node_to_find ){
                    flag=true;
                    continue;
                }
                if(nd->left)
                    q.push(nd->left);
                if(nd->right)
                    q.push(nd->right);
            }
            
        }
        if(q.empty()){
            ans.push_back(-1);
        }
        while(!q.empty()){
            //Node *nd=q.front();
            ans.push_back(q.front()->data);
            q.pop();
        }
        return ans;
    }
    
};
