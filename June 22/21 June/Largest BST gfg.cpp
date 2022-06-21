class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int maxSize=1;
    pair<pair<int,bool>,pair<int,int>> solve(Node *root){ //{ {node_count,isBST} , {min_node,max_node} }
        if(!root) return { {0,true} , {INT_MAX,INT_MIN} };
        
        pair<pair<int,bool>,pair<int,int>> left=solve(root->left),right=solve(root->right);
        
        bool leftBST= left.first.second && (root->data > left.second.second);
        bool rightBST=right.first.second && (root->data < right.second.first);
        bool isBST = leftBST & rightBST;
        
        int _min=min({left.second.first, root->data, right.second.first});
        int _max=max({left.second.second, root->data, right.second.second});
        
        int totalNodes=left.first.first + right.first.first+1;
        
        if(isBST){
            maxSize=max(maxSize,totalNodes);
            return {{totalNodes,true},{_min,_max}} ;
        }
        else
          return {{0,false},{_min,_max}} ;
    }
    int largestBst(Node *root)
    {
    	solve(root);
    	return maxSize;
    }
};
