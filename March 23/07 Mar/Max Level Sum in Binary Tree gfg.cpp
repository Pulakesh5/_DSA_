int maxLevelSum(Node* root) {
        // Your code here
        int maxSum=INT_MIN, levelSum=0, qs;
        
        queue<Node*> q;
        if(root)
            q.push(root);
        while(!q.empty())
        {
            qs=q.size();
            levelSum=0;
            for(int i=0;i<qs;i++)
            {
                Node* frnt = q.front();
                q.pop();
                levelSum+=frnt->data;
                if(frnt->left) q.push(frnt->left);
                if(frnt->right) q.push(frnt->right);
            }
            maxSum=max(maxSum,levelSum);
        }
        return maxSum;
    }
