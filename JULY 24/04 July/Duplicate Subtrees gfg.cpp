class Solution {
  public:
    vector<Node*> duplicates;
    map<string,int> mp;
    string process(Node* root)
    {
        if(root==nullptr)
            return "";
        string lTree = process(root->left);
        string rTree = process(root->right);
        string traversal = to_string(root->data) + "$" + lTree + "$" + rTree;
        
        if(mp.find(traversal)!=mp.end() && mp[traversal]==1)
        {
            duplicates.push_back(root);
        }
        mp[traversal]++;
        return traversal;
    }
    vector<Node*> printAllDups(Node* root) {
        // Code here
        process(root);
        return duplicates;
    }
};
