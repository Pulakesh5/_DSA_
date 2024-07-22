class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int maxBSTSize = 1;
    vector<int> findBST(Node* root) // return {min, max, size}. size=-1 if not BST
    {
        if(root==nullptr)
            return {0,0,0};
        if(root->left==nullptr && root->right==nullptr)
        {
            return {root->data, root->data, 1};
        }
        
        
        vector<int> lTree, rTree;
        if(root->left!=nullptr)
            lTree = findBST(root->left);
        else 
            lTree = {root->data, root->data-1, 0};
        
        if(root->right != nullptr)
            rTree = findBST(root->right); 
        else 
            rTree = {root->data+1, root->data, 0};
        
        if(lTree[2]==-1 || rTree[2]==-1)
            return {-1,-1,-1};
        
        maxBSTSize = max({maxBSTSize, lTree[2], rTree[2]});
        
        int SubTreeSize = lTree[2]+rTree[2]+1;
        
        if(lTree[1]<root->data && root->data<rTree[0])
        {
            maxBSTSize = max(maxBSTSize, SubTreeSize);
            return {lTree[0], rTree[1], SubTreeSize};
        }
        
        return {-1, -1, -1};
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	if(root==nullptr)
    	    return 0;
    	findBST(root);
    	return maxBSTSize;
    	
    }
};
