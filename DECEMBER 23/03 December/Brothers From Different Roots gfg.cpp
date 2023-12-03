class Solution
{
public:
    void inorder(Node* root, vector<int> &v)
    {
        if(!root)
            return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int> traversal1, traversal2;
        inorder(root1, traversal1);
        inorder(root2, traversal2);
        
        int n1 = traversal1.size(), n2 = traversal2.size();
        int l=0, r=traversal2.size()-1, sum, count=0;
        while(l<n1 && r>-1)
        {
            sum = traversal1[l]+traversal2[r];
            if(sum<x)
                l++;
            else if(sum>x)
                r--;
            else
            {
                count++;
                l++;
                r--;
            }
        }
        return count;
    }
};
