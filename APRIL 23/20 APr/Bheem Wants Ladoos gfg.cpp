class Solution{

    public:
    Node* start = NULL ;
    void target(Node* root , int home )
    {
        if(root==NULL)
        return ; 
        
        if(root->data==home)
        {
            start=root ;
            return; 
        } 
        
        target(root->left, home ); 
        target(root->right, home ); 
    }
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        target(root, home ); 
        
        if(start==NULL)
        return 0 ; 
        
        map<int ,vector<int>>adj ; 
        queue<Node* >q; 
        q.push(root) ;
        
        while(!q.empty())
        {
            int len= q.size() ;
            while(len--)
            {
            Node* temp= q.front();
            q.pop() ;
            
            if(temp->left)
            {
                adj[temp->data].push_back(temp->left->data);
                adj[temp->left->data].push_back(temp->data);
                q.push(temp->left) ;
            }
            if(temp->right)
            {
                adj[temp->data].push_back(temp->right->data);
                adj[temp->right->data].push_back(temp->data);
                q.push(temp->right);
            }
            
            }
        }
        
        map<int, int >vis; 
        queue<int>q1; 
        int ans = 0 ; 
        q1.push(start->data) ;
        vis[start->data]=1; 
        
        while(!q1.empty())
        {
            int len = q1.size() ;
            while(len--)
            {
                int ptr =q1.front() ; 
                q1.pop() ;
                ans+=ptr; 
                for(auto it: adj[ptr])
                {
                    if(!vis[it])
                    {
                        vis[it]=1; 
                        q1.push(it); 
                    }
                }
                
            }
            k-- ;
            if(k==-1)
            break ;
        }
        
        return ans ;  
    }


};
