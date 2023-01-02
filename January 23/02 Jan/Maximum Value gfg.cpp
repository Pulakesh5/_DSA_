    vector<int> maximumValue(Node* _node) {
        //code here
        if(!_node) return {};
        
        queue<Node*> q;
        vector<int> ans;
        vector<int> row;
        q.push(_node);
        ans.push_back(_node->data);
        
        int qs,mx;
        while(!q.empty())
        {
            qs=q.size();
            row.clear();
            for(int i=0;i<qs;i++)
            {
                Node* node = q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                    row.push_back(node->left->data);
                }
                if(node->right)
                {
                    q.push(node->right);
                    row.push_back(node->right->data);
                }
            }

            if(row.size())
            {
                mx=*max_element(row.begin(), row.end());
                ans.push_back(mx);
            }
            
        }
        return ans;
    }
