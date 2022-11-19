class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
        queue<Node*> q1,q2;
        if(!root1 && !root2) return true;
        
        if(!root1 && root2 || root1 && !root2) return false;
        q1.push(root1);
        q2.push(root2);
        
        Node *node1,*node2;
        
        while(!q1.empty() && !q2.empty())
        {
            int sz1=q1.size(),sz2=q2.size();
            if(sz1!=sz2) return false;
            vector<int> v1,v2;
            
            for(int i=0;i<sz1;i++)
            {
                node1=q1.front();
                v1.push_back(node1->data);
                node2=q2.front();
                v2.push_back(node2->data);
                
                q1.pop();
                q2.pop();
                
                if(node1->right) q1.push(node1->right);
                if(node1->left)  q1.push(node1->left);
                
                if(node2->right) q2.push(node2->right);
                if(node2->left)  q2.push(node2->left);
            }
            
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            if(v1!=v2) return false;
        }
        
        return true;
    }
};
