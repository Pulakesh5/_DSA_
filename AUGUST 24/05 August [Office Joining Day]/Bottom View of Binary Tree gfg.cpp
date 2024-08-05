class Solution {
  public:

    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int> view;
        vector<int> viewList;
        if(root==nullptr)
            return viewList;
            
        int distance = 0;
        
        queue<pair<Node*,int>> q;
        q.push({root, distance});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            distance = it.second;
            view[distance] = node->data;
            if(node->left)
                q.push({node->left, distance-1});
            if(node->right)
                q.push({node->right, distance+1});
        }
        for(auto it:view)
            viewList.push_back(it.second);
        return viewList;
    }
};
