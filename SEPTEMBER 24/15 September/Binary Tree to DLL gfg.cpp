class Solution {
  public:
    void DLL(Node*&tail,Node *&head ,vector<int>&ans){
    for(int i=0;i<ans.size();i++){
        if(tail==NULL){
            Node*temp=new Node(ans[i]);
            tail=temp;
            head=temp;
        }
        else{
            Node*temp=new Node(ans[i]);
            tail->right=temp;
            temp->left=tail;
            tail=temp;
        }
      }
    }
    void solve(Node*root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        solve(root->left,ans);
        ans.push_back(root->data);
        solve(root->right,ans);
    }
    Node* bToDLL(Node* root) {
        vector<int> ans;
        solve(root, ans);
        Node*tail = NULL;
        Node*head = NULL;
        DLL(tail, head, ans);
        return head;
    }
};
