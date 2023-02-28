class Solution {
public:
    string traverse(TreeNode* root, map<string,int> &mp, vector<TreeNode*> &duplicates)
    {
        if(!root) return "#";
        string left = traverse(root->left, mp, duplicates);
        string right = traverse(root->right, mp, duplicates);

        string s = left + ","+right+","+to_string(root->val);

        if(mp[s]==1) duplicates.push_back(root);

        mp[s]++;

        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> duplicates;
        map<string,int> mp;
        traverse(root, mp, duplicates);
        return duplicates;
    }
};
