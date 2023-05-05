set<int> rec(Node* root, int &count, int k)
    {
        set<int> st;
        if(!root)
            return st;
        set<int> st_left = rec(root->left, count, k);
        set<int> st_right = rec(root->right, count, k);
        for(auto it:st_left)
            st.insert(it);
        for(auto it:st_right)
            st.insert(it);
        st.insert(root->data);
        if(st.size()<=k) 
            count++;
        return st;
    }
    int goodSubtrees(Node *root,int k){
        // Code here
        int count=0;
        rec(root, count, k);
        return count;
    }
