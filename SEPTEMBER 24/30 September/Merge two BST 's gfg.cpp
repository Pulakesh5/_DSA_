class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void traversal(Node *root, vector<int> &v)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* node = q.front();
            q.pop();
            v.push_back(node->data);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> v;
        traversal(root1, v);
        traversal(root2, v);
        sort(v.begin(), v.end());
        return v;
    }
};
