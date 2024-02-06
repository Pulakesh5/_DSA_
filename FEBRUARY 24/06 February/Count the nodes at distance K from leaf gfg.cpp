class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    bool heightK(Node* root, int k)
    {
        if(!root)
            return 0;
        if(root->left==nullptr && root->right==nullptr)
        {
            return (k==0);
        }
        if(heightK(root->left, k-1) || heightK(root->right, k-1))
            return true;
        return false;
    }
    int count(Node* root, int k)
    {
        if(!root)
            return 0;
        if(heightK(root, k))
            return 1 + count(root->left, k) + count(root->right, k);
        return count(root->left, k) + count(root->right, k);
        
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
    	//Add your code here. 
    	return count(root, k);
    }
};
