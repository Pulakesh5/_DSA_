    int maxDifferenceBST(Node *root,int target){
        // Code here
        Node* targetNode=NULL;
        
        int targetDistance = rootToTarget(root, target, targetNode);
        
        if(!targetNode) return -1;
        
        int leafDistance = targetToLeaf(targetNode);
        //cout<<targetDistance<<" "<<leafDistance<<endl;
        return targetDistance - leafDistance;
        
    }
    int rootToTarget(Node* root, int target, Node* &targetNode)
    {
        if(!root) return INT_MIN;
        
        if(target>root->data)
            return root->data+rootToTarget(root->right, target, targetNode);
        else if(target<root->data)
            return root->data+rootToTarget(root->left, target, targetNode);
        else if (target == (root->data))
        {
            targetNode=root;
            //cout<<"target found"<<endl;
            return root->data;
        }
    }
    int targetToLeaf(Node* root)
    {
        if(!root) return INT_MAX/2;
        if(!(root->left) && !(root->right)) return root->data;
        
        int left = targetToLeaf(root->left);
        int right = targetToLeaf(root->right);
        
        return root->data+min(left,right);
    }
