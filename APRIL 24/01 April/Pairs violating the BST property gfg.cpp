class Solution {
    private:
    void inorder(Node* root, vector<int> &v)
    {
        if(root==nullptr)
            return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    void merge(vector<int> &v, int l, int m, int r)
    {
        vector<int> tmp;
        int left = l, right = m+1;
        while(left<=m && right<=r)
        {
            if(v[left]<=v[right])
                tmp.push_back(v[left++]);
            else
            {
                countPairs+=(m-left+1);
                tmp.push_back(v[right++]);
            }
        }
        
        while(left<=m)
            tmp.push_back(v[left++]);
        while(right<=r)
            tmp.push_back(v[right++]);
        
        for(int i=l; i<=r; i++)
            v[i] = tmp[i-l];
    }
    void mergeSort(vector<int> &v, int l, int r)
    {
        if(l>=r)
            return;
        int mid = (l+r)/2;
        mergeSort(v,l,mid);
        mergeSort(v,mid+1,r);
        merge(v,l,mid,r);
    }
    int countPairs=0;
    public:
    
    int pairsViolatingBST(int n, Node *root) {
        // your code goes here
        vector<int> traversal;
        
        inorder(root, traversal);
        
        mergeSort(traversal, 0, n-1);
        return countPairs;
        
    }
    /*
        50 -> 4
        10 -> 1
        20 -> 1
        40 -> 2
        30 -> 2
    */
};
