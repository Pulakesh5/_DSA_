class Solution {
    private:
    void left_traversal(Node* root, vector<int> &traversal)
    {
        if(root==nullptr ||(root->left==nullptr && root->right==nullptr))
            return;
        traversal.push_back(root->data);
        if(root->left)
            left_traversal(root->left, traversal);
        else
            left_traversal(root->right, traversal);
    }
    void right_traversal(Node* root, vector<int> &traversal)
    {
        if(root==nullptr || (root->left==nullptr && root->right==nullptr))
            return;
        if(root->right)
            right_traversal(root->right, traversal);
        else
            right_traversal(root->left, traversal);
        traversal.push_back(root->data);
    }
    void leaf_traversal(Node* root, vector<int> &leaves)
    {
        if(root==nullptr)
            return;
        
        if(root->left==nullptr && root->right==nullptr)
        {
            leaves.push_back(root->data);
        }
        leaf_traversal(root->left, leaves);
        leaf_traversal(root->right, leaves);
    }
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        if(root==nullptr)
            return {};
        vector<int> lBoundary, rBoundary, leaves;
        vector<int> boundary_traversal;
        
        boundary_traversal.push_back(root->data);
        
        left_traversal(root->left, boundary_traversal);
        leaf_traversal(root->left, boundary_traversal);
        leaf_traversal(root->right, boundary_traversal);
        right_traversal(root->right, boundary_traversal);
        
        return boundary_traversal;
    }
};
