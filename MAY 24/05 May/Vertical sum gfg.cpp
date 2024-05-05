class Solution{
    private:
    void traverse(Node* root, int line, map<int,int> &lineSum)
    {
        if(root==nullptr)
            return;
        traverse(root->left,line-1,lineSum);
        lineSum[line]+=(root->data);
        traverse(root->right,line+1,lineSum);
    }
  public:
    vector <int> verticalSum(Node *root) {
        // add code here.
        map<int,int> lineSum;
        traverse(root, 0, lineSum);
        vector<int> lineSumArr;
        for(auto it:lineSum)
            lineSumArr.push_back(it.second);
        return lineSumArr;
    }
};
