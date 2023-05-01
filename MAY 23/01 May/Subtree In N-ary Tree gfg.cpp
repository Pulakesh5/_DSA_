class Solution{
public:
    map<string, int> subTrees;
    int duplicateSubtreeNaryTree(Node *root){
        // Code here
        traverse(root);
        int count=0;
        for(auto it:subTrees)
            count+=(it.second>1);
        return count;
    }
    
    string traverse(Node* root)
    {
        string str = to_string(root->data);
        str+=":";
        vector<string> vs;
        
        for(auto it:root->children)
            vs.push_back(traverse(it));
        for(string s:vs)
            str+=(s+",");
        
        subTrees[str]++;
        return str;
    }
    
};
