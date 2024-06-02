class Solution {
  public:
    vector<int> constructList(int n, vector<vector<int>> &q) {
        // code here
        int cont_xor = 0;
        vector<int> list;
        
        for(int i=n-1; i>=0; i--)
        {
            if(q[i][0]==0)
                list.push_back(q[i][1]^cont_xor);
            else
                cont_xor^=q[i][1];
        }
        list.push_back(cont_xor);
        sort(list.begin(), list.end());
        return list;
    }
};
