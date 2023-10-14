class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    void inorder(Node* root,unordered_set<int>& st){
        if (!root) return ;
        inorder(root -> left, st);
        st.insert(root -> data);
        inorder(root -> right, st);
    }
    void inorder1(Node* root, unordered_set<int>& st, vector<int>& arr){
        if (!root) return ;
        inorder1(root -> left, st, arr);
        if (st.find(root -> data) != st.end()){
            arr.push_back(root -> data);
        }
        inorder1(root -> right, st, arr);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
       unordered_set<int>st;
       vector<int>arr;
       inorder(root1,st);
       inorder1(root2,st,arr);
       return arr;
    }
};
