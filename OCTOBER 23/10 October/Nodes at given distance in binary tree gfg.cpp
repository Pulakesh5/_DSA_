    Node *targetNode;
    void tar(Node *root, int target , unordered_map<Node*,Node*>&parent ){
       
        if(root->data ==target ){
            targetNode =root;
        }
        
        if(root->left){
            parent[root->left]=root;
            tar(root->left,target,parent);
        }
        
        if(root->right){
            parent[root->right] =root;
            tar(root->right,target,parent);
        }
        
        return;
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {   
        unordered_map<Node* ,Node*>parent;
        targetNode =nullptr;
        tar(root,target,parent);
        
        queue<pair<Node*,int>>q;
        q.push({targetNode , 0 });
        
        unordered_set<Node*>visited;
        visited.insert(targetNode);
        vector<int>ans;
        
        while(!q.empty()){
            Node* node = q.front().first;
            int dis =q.front().second;
            
            q.pop();
            
            
            if(dis==k){
                ans.push_back(node->data);
                continue;
            }
            
            
            if(parent.find(node)!=parent.end()){
                if(visited.find(parent[node])==visited.end()){
                    visited.insert(parent[node]);
                    q.push({parent[node], dis+1});
                }
            }
            
            if(node->left && visited.find(node->left)==visited.end()){
                visited.insert(node->left);
                q.push({node->left ,dis+1});
            }
            
            if(node->right && visited.find(node->right)==visited.end()){
                visited.insert(node->right);
                q.push({node->right ,dis+1});
            }
        }
        
        sort(ans.begin() ,ans.end());
        return ans;
    }
    
