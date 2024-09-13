class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int N = arr.size();
        vector<int> ans, preXOR(N+1);

        for(int i=1; i<=N; i++)
            preXOR[i] = preXOR[i-1]^arr[i-1];
        
        for(vector<int> query:queries)
        {
            ans.push_back(preXOR[query[1]+1] ^ preXOR[query[0]]);
        }

        return ans;
    }
};
