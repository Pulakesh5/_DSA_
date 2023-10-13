class Solution{

public:
    int floorX = INT_MAX;
    void traverse(Node* root, int x)
    {
        if(!root)
            return;
        if(x < root->data)
            traverse(root->left, x);
        else if(x == root->data)
            floorX = root->data;
        else
        {
            floorX = root->data;
            traverse(root->right, x);
        }
    }
    int floor(Node* root, int x) {
        // Code here
        traverse(root, x);
        if(floorX==INT_MAX)
            return -1;
        return floorX;
    }
};
